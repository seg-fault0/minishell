/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:47:15 by wimam             #+#    #+#             */
/*   Updated: 2025/07/06 05:02:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chiled(t_ms *ms, int rfd, int *pfd)
{
	char	**tmp;

	signal(SIGINT, SIG_DFL);
	tmp = ms->cmd.cmd[ms->cmd.counter];
	if (tmp[0] == NULL)
		return (close(rfd), close_pipe(pfd), ft_exit(ms));
	fd_manager(ms, rfd, pfd);
	if (is_builtin(tmp[0]) == TRUE)
		builtin_exe(ms, tmp[0]);
	else if (ft_strchr(tmp[0], '/'))
		execve(tmp[0], tmp, ms->env);
	ms->cmd.cur_exit_code = get_exit_code(ms);
	ft_exit(ms);
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
		signal(SIGINT, SIG_IGN);
		ms->cmd.pids[ms->cmd.counter] = pid;
		ms->cmd.counter++;
		close(pfd[1]);
		ft_start(ms, pfd[0]);
		close(pfd[0]);
	}
}
