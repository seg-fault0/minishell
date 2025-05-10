/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:26:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 12:00:45 by wimam            ###   ########.fr       */
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
	ms->parse.instr = NULL;
	ms->parse.oustr = NULL;
	ms->fds.infd = STDIN;
	ms->fds.oufd = STDOUT;
	ms->fds.append_flag = FALSE;
}

void	setup_outfd(t_ms *ms)
{
	int	*fd;

	fd = &ms->fds.oufd;
	if (ms->fds.append_flag == TRUE)
		*fd = open(ms->parse.oustr, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd = open(ms->parse.oustr, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
		return (err_msg(ERR_OPEN_F));
}

void	setup_infd(t_ms *ms)
{
	ms->fds.infd = open(ms->parse.instr, O_RDONLY);
	if (ms->fds.infd < 0)
		err_msg(ERR_OPEN_F);
}

void	setup_fds(t_ms *ms)
{
	if (ms->parse.instr)
		setup_infd(ms);
	if (ms->parse.oustr)
		setup_outfd(ms);
}
