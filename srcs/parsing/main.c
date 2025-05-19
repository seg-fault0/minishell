/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 15:45:07 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_allocator(t_ms *ms)
{
	ms->parse.tmp2d = split_cmd(ms->input);
	ms->parse.oufiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	ms->parse.infiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	ms->parse.cmd = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	if (!ms->parse.tmp2d || !ms->parse.oufiles || !ms->parse.infiles
		|| !ms->parse.cmd)
		return (FALSE);
	return (TRUE);
}

void	ft_parse(t_ms *ms)
{
	ms->parse.cmd_nbr = cmd_counter(ms->input);
	if (ft_allocator(ms) == FALSE)
		return ;
	parse_outfile(ms);
	parse_infile(ms);
	parse_cmd(ms);
}
