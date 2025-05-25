/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 16:38:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(t_ms *ms)
{
	char	*path;
	int		counter;

	counter = ms->cmd.counter;
	if (ms->cmd.cmd[counter][1] == NULL)
		path = get_env(ms->env, "HOME");
	else
		path = ms->cmd.cmd[counter][1];
	if (!path)
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	if (chdir(path) == -1)
	{
		ms->cmd.cur_exit_code = 1;
		err_msg(ERR_CHDIR_F);
	}
}

void	ft_pwd(t_ms *ms)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		ms->cmd.cur_exit_code = 1;
		return (err_msg(ERR_PWD_F));
	}
	printf("%s\n", pwd);
}

void	built_in_exit(t_ms *ms)
{
	ms->cmd.cur_exit_code = ft_atoi(ms->cmd.cmd[ms->cmd.counter][1]);
	ft_exit(ms);
}

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0)
		print_env(ms);
	else if (ft_memcmp(cmd, "exit", 4) == 0)
		built_in_exit(ms);
	else if (ft_memcmp(cmd, "cd", 2) == 0)
		ft_chdir(ms);
	else if (ft_memcmp(cmd, "echo", 4) == 0)
		ft_echo(ms);
	else if (ft_memcmp(cmd, "pwd", 3) == 0)
		ft_pwd(ms);
	else if (ft_memcmp(cmd, "export", 6) == 0)
		set_env(ms);
	else if (ft_memcmp(cmd, "unset", 5) == 0)
		unset_env(ms);
	if (is_main_process_exe(cmd) == TRUE && ms->cmd.counter == 0)
		return ;
	ft_exit(ms);
}
