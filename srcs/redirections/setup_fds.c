/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:26:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 13:14:47 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fds(t_ms *ms)
{
	if (ms->fds.infd > 2)
		close (ms->fds.infd);
	if (ms->fds.oufd > 2)
		close (ms->fds.oufd);
	free(ms->fds.instr);
	free(ms->fds.oustr);
	ms->fds.instr = NULL;
	ms->fds.oustr = NULL;
	ms->fds.infd = STDIN;
	ms->fds.oufd = STDOUT;
}

void	setup_outfd(t_ms *ms)
{
	ms->fds.oufd = open(ms->fds.oustr, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ms->fds.oufd < 0)
		return (err_msg(ERR_OPEN_F));
}

void	setup_infd(t_ms *ms)
{
	ms->fds.infd = open(ms->fds.instr, O_RDONLY);
	if (ms->fds.infd < 0)
		err_msg(ERR_OPEN_F);
}

void	setup_fds(t_ms *ms)
{
	if (ms->fds.instr)
		setup_infd(ms);
	if (ms->fds.oustr)
		setup_outfd(ms);
}
