/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 16:20:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->env[i])
		printf("%s\n", ms->env[i++]);
}

void	ft_chdir(t_ms *ms)
{
	char	*path;

	if (ms->cmd.cmd[0][1] == NULL)
		path = getenv("HOME");
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
		printf("%s ", ms->cmd.cmd[counter][i]);
	printf("\n");
}

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0)
		ft_env(ms);
	else if (ft_memcmp(cmd, "exit", 4) == 0)
		ft_exit(ms);
	else if (ft_memcmp(cmd, "cd", 2) == 0)
		ft_chdir(ms);
	else if (ft_memcmp(cmd, "echo", 4) == 0)
		ft_echo(ms);
}
