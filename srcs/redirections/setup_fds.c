/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:26:15 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 11:38:33 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_fds(t_ms *ms)
{
	if (!ms->fds.instr)
		ms->fds.infd = STDIN;
	else
		setup_infd(ms);
	if (!ms->fds.oustr)
		ms->fds.infd = STDOUT;
	else
		setup_outfd(ms);
}
