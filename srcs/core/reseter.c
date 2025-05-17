/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reseter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:35:00 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 11:52:57 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_reseter(t_ms *ms)
{
	free3size(ms->parse.cmd, ms->parse.cmd_nbr);
	free3size(ms->parse.infiles, ms->parse.cmd_nbr);
	free3size(ms->parse.oufiles, ms->parse.cmd_nbr);
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
	ms->fd.out = NULL;
}
