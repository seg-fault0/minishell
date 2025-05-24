/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/05/24 10:49:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(t_ms *ms)
{
	char	*path;

	if (ms->cmd.cmd[0][1] == NULL)
		path = get_env(ms->env, "HOME=");
	else
		path = ms->cmd.cmd[0][1];
	if (!path)
		return ;
	if (chdir(path) == -1)
		err_msg(ERR_CHDIR_F);
}

void	ft_echo(t_ms *ms)
{
	int	counter;
	int	i;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		if (ft_strstr(ms->cmd.cmd[counter][i], "$?"))
			printf("%d", ms->cmd.last_exit_code);
		else
			printf("%s", ms->cmd.cmd[counter][i]);
	}
	printf("\n");
}

void	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
		return (err_msg(ERR_PWD_F));
	printf("%s\n", pwd);
}

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0)
		print_env(ms);
	else if (ft_memcmp(cmd, "exit", 4) == 0)
		ft_exit(ms);
	else if (ft_memcmp(cmd, "cd", 2) == 0)
		ft_chdir(ms);
	else if (ft_memcmp(cmd, "echo", 4) == 0)
		ft_echo(ms);
	else if (ft_memcmp(cmd, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_memcmp(cmd, "export", 6) == 0)
		set_env(ms);
	else if (ft_memcmp(cmd, "unset", 5) == 0)
		unset_env(ms);
	if (is_main_process_exe(cmd) == FALSE)
		exit(0);
}
