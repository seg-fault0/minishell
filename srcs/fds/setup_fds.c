/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:26:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 14:40:52 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fds(t_ms *ms)
{
	if (ms->fds.infd > 2)
		close (ms->fds.infd);
	if (ms->fds.oufd > 2)
		close (ms->fds.oufd);
	free(ms->parse.instr);
	free(ms->parse.oustr);
	free(ms->parse.delimiter);
	ms->parse.instr = NULL;
	ms->parse.oustr = NULL;
	ms->fds.infd = STDIN;
	ms->fds.oufd = STDOUT;
	ms->fds.append_flag = FALSE;
	ms->parse.delimiter = NULL;
}

void	setup_fds(t_ms *ms)
{
	if (ms->parse.instr || ms->parse.delimiter)
		setup_infd(ms);
	if (ms->parse.oustr)
		setup_outfd(ms);
}
