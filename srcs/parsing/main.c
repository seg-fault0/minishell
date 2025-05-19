/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 12:54:17 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(t_ms *ms)
{
	ms->parse.cmd_nbr = cmd_counter(ms->input);
	ms->parse.tmp2d = split_cmd(ms);
	if (!ms->parse.tmp2d)
		return ;
	parse_outfile(ms);
	parse_infile(ms);
	parse_cmd(ms);
}
