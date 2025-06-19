/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:47:15 by wimam             #+#    #+#             */
/*   Updated: 2025/06/19 20:39:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait(t_ms *ms)
{
	int	i;
	int	id;

	i = 0;
	while (i < ms->cmd.counter)
	{
		id = ms->cmd.pids[i];
		waitpid(id, &ms->cmd.cur_exit_code, 0);
		i++;
	}
	ms->cmd.cur_exit_code = WEXITSTATUS(ms->cmd.cur_exit_code);
}

void	ft_chiled(t_ms *ms, int rfd, int *pfd)
{
	char	**tmp;
	int		status;

	status = 0;
	tmp = ms->cmd.cmd[ms->cmd.counter];
	if (tmp[0] == NULL || tmp[0][0] == '\0')
		ft_exit(ms);
	fd_manager(ms, rfd, pfd);
	if (is_builtin(tmp[0]) == TRUE)
		builtin_exe(ms, tmp[0]);
	else
		status = execve(tmp[0], tmp, ms->env);
	if (status == -1)
	{
		ms->cmd.cur_exit_code = get_exit_code(ms);
		ft_exit(ms);
	}
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
		ms->cmd.pids[ms->cmd.counter] = pid;
		ms->cmd.counter++;
		close(pfd[1]);
		ft_start(ms, pfd[0]);
		close(pfd[0]);
	}
}
