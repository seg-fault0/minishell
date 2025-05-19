/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 11:28:01 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(t_ms *ms)
{
	int		i;

	i = 0;
	ms->parse.cmd_nbr = cmd_counter(ms->input);
	ms->parse.tmp2d = split_cmd(ms);
	if (!ms->parse.tmp2d)
		return ;
	while (i < ms->parse.cmd_nbr)
	{
		if (char_search(ms->parse.tmp2d[i], '>') == TRUE)
			parse_outfile(ms);
		if (char_search(ms->parse.tmp2d[i], '<') == TRUE)
			parse_infile(ms);
		i++;
	}
	parse_cmd(ms);
}
