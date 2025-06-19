/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:56:07 by wimam             #+#    #+#             */
/*   Updated: 2025/06/19 20:09:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ou_fd_manager(t_ms *ms, int pfd, int counter)
{
	if (ms->fd.out[counter] == -1)
		exit(1);
	if (ms->fd.out[counter] >= -1)
	{
		if (dup2(ms->fd.out[counter], STDOUT) == -1)
			return (err_msg(ERR_DUP2_F), exit(0));
	}
	else if (ms->cmd.counter == ms->cmd.max_counter - 1)
		return ;
	else if (dup2(pfd, STDOUT) == -1)
		return (err_msg(ERR_DUP2_F), exit(0));
}

static void	in_fd_manager(t_ms *ms, int rfd, int counter)
{
	if (ms->fd.in[counter] == -1)
		exit(1);
	if (ms->fd.in[counter] >= 0)
	{
		if (dup2(ms->fd.in[counter], STDIN) == -1)
			return (err_msg(ERR_DUP2_F), exit(1));
	}
	else if (ms->cmd.counter == 0)
		return ;
	else if (dup2(rfd, STDIN) == -1)
		return (err_msg(ERR_DUP2_F), exit(1));
}

void	fd_manager(t_ms *ms, int rfd, int *pfd)
{
	int	counter;

	counter = ms->cmd.counter;
	in_fd_manager(ms, rfd, counter);
	ou_fd_manager(ms, pfd[1], counter);
	close_pipe(pfd);
}
