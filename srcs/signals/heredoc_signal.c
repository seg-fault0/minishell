/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:43:04 by wimam             #+#    #+#             */
/*   Updated: 2025/07/02 00:39:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_linker(int *arg)
{
	static int	*pfd;

	if (arg)
		pfd = arg;
	else
		close_pipe(pfd);
}

static void	handle_sigint(int sig)
{
	(void)sig;
	pipe_linker(NULL);
	exit(130);
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	printf("%s", HERE_DOC);
}

void	heredoc_signals(int *pfd)
{
	pipe_linker(pfd);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
