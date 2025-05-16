/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/16 18:33:55 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(t_ms *ms)
{
	char	*tmp;
	int		i;

	i = 0;
	ms->parse.cmd_nbr = 0;
	tmp = ft_strdup(ms->input);
	if (!tmp)
		return ;
	if (ms->parse.tmp2d)
		free2d_buffer(ms->parse.tmp2d);
	ms->parse.tmp2d = quote_protect(tmp, strlen(tmp) + 1);
	if (!ms->parse.tmp2d)
		return (free(tmp));
	while (ms->parse.tmp2d[ms->parse.cmd_nbr])
		ms->parse.cmd_nbr++;
	while (i < ms->parse.cmd_nbr)
	{
		if (char_search(ms->parse.tmp2d[i], '>') == TRUE)
			parse_outfile(ms);
		if (char_search(ms->parse.tmp2d[i], '<') == TRUE)
			parse_infile(ms);
		i++;
	}
	parse_cmd(ms);
	free(tmp);
}
