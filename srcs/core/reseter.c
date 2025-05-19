/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reseter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:35:00 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 15:57:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_reseter(t_ms *ms)
{
	free3size(ms->parse.cmd, ms->parse.cmd_nbr);
	free3size(ms->parse.infiles, ms->parse.cmd_nbr);
	free3size(ms->parse.oufiles, ms->parse.cmd_nbr);
	free2(ms->parse.tmp2d, HEAP);
	ms->parse.tmp2d = NULL;
	ms->parse.cmd = NULL;
	ms->parse.infiles = NULL;
	ms->parse.oufiles = NULL;
}

void	cmd_reseter(t_ms *ms)
{
	free2(ms->cmd.paths, HEAP);
	free(ms->cmd.pids);
	ms->cmd.paths = NULL;
	ms->cmd.cmd = NULL;
	ms->cmd.pids = NULL;
}

void	fd_reseter(t_ms *ms)
{
	free(ms->fd.out);
	free(ms->fd.in);
	free(ms->fd.append);
	ms->fd.out = NULL;
	ms->fd.in = NULL;
	ms->fd.append = NULL;
}
