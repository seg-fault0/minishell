/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:47:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 15:03:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	fd_manager(t_ms *ms, int rfd, int wfd)
{
	if (dup2(rfd, STDIN) == -1)
		exit(0);
	if (ms->cmd.counter == ms->cmd.max_counter - 1)
	{
		if (dup2(0, STDOUT) == -1)
			exit(0);
	}
	else
	{
		if (dup2(wfd, STDOUT) == -1)
			ft_exit(ms);
	}
}

static void	ft_chiled(t_ms *ms, int rfd, int *pfd)
{
	int	count;
	int	failed;

	fd_manager(ms, rfd, pfd[1]);
	count = ms->cmd.counter;
	close (rfd);
	close_pipe(pfd);
	failed = execve(ms->cmd.cmd[count][0], ms->cmd.cmd[count], NULL);
	if (failed == -1)
	{
		printf("ERR\n");
		exit(127);
	}
}

void	ft_exe(t_ms *ms, int rfd)
{
	int	pfd[2];
	int	pid;
	
	if (ms->cmd.counter == ms->cmd.max_counter)
		return ;
	if (pipe(pfd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
		ft_chiled(ms, rfd, pfd);
	else
	{
		close_pipe((int []){pfd[1], rfd});
		ms->cmd.counter++;
		ft_exe(ms, pfd[0]);
		close(pfd[0]);
	}
}