/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:47:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 17:32:31 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fdmanager(t_ms *ms, int rfd, int *pfd)
{
	dup2(rfd, 0);
	close(rfd);
	if (ms->cmd.counter < ms->cmd.max_counter - 1)
		dup2(pfd[1], 1);
}

void	ft_chiled(t_ms *ms, int rfd, int *pfd)
{
	char	**tmp;
	int		status;

	ft_fdmanager(ms, rfd, pfd);
	tmp = ms->cmd.cmd[ms->cmd.counter];
	if (is_builtin(tmp[0]) == TRUE)
		builtin_exe(ms, tmp[0]);
	else
		status = execve(tmp[0], tmp, ms->env);
	if (status == -1)
		err_msg(ERR_EXECVE_F);
	exit(0);
}

void	ft_start(t_ms *ms, int rfd)
{
	int	pfd[2];
	int	pid;

	if (ms->cmd.counter == ms->cmd.max_counter)
		return ;
	if (pipe(pfd) == -1)
		err_msg(ERR_PIPE_F);
	pid = fork();
	if (pid == -1)
		err_msg(ERR_FORK_F);
	if (pid == 0)
		ft_chiled(ms, rfd, pfd);
	else
	{
		ms->cmd.counter++;
		close(pfd[1]);
		ft_start(ms, pfd[0]);
		close(pfd[0]);
		wait(NULL);
	}
}

void	ft_exe(t_ms *ms)
{
	if (ft_strcmp(ms->cmd.cmd[0][0], "cd"))
		ft_chdir(ms);
	else if (ft_strcmp(ms->cmd.cmd[0][0], "exit"))
		ft_exit(ms);
	else if (ft_strcmp(ms->cmd.cmd[0][0], "export"))
		set_env(ms);
	else if (ft_strcmp(ms->cmd.cmd[0][0], "unset"))
		unset_env(ms);
	else
		ft_start(ms, 0);
}
