/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/06/17 18:12:18 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_allocator(t_ms *ms)
{
	ms->parse.tmp2d = split_cmd(ms->input);
	ms->parse.oufiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	ms->parse.infiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	ms->parse.cmd = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	ms->fd.append = ft_calloc(ms->parse.cmd_nbr, sizeof(size_t));
	ms->fd.heredoc = ft_calloc(ms->parse.cmd_nbr, sizeof(size_t));
	if (!ms->parse.tmp2d || !ms->parse.oufiles || !ms->parse.infiles
		|| !ms->parse.cmd || !ms->fd.append || !ms->fd.heredoc)
		return (FALSE);
	return (TRUE);
}

void	ft_parse(t_ms *ms)
{
	ms->parse.cmd_nbr = cmd_counter(ms->input);
	if (ft_allocator(ms) == FALSE)
		return ;
	expand_vars(ms);
	parse_outfile(ms);
	parse_infile(ms);	
	parse_cmd(ms);
}
