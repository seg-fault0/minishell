/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:26:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 12:12:04 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fds(t_ms *ms)
{
	free(ms->fds.instr);
	free(ms->fds.oustr);
	ms->fds.instr = NULL;
	ms->fds.oustr = NULL;
	ms->fds.infd = STDIN;
	ms->fds.oufd = STDOUT;
}

void	setup_fds(t_ms *ms)
{
	ms->fds.instr = ft_strdup("Makefile");
	if (ms->fds.instr)
		setup_infd(ms);
	if (ms->fds.oustr)
		setup_outfd(ms);
}
