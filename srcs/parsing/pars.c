/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/15 17:55:57 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(t_ms *ms)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(ms->input);
	if (!tmp)
		return ;
	ms->parse.cmd_nbr = pipe_counter(ms->input, '|') + 1;
	ms->parse.tmp2d = quote_protect(tmp, strlen(tmp) + 1);
	while (i < ms->parse.cmd_nbr)
	{
		if (char_search(ms->parse.tmp2d[i], '>') == TRUE)
			parse_outfile(ms);
		if (char_search(ms->parse.tmp2d[i], '<') == TRUE)
			parse_infile(ms);
		parse_cmd(ms);
		i++;
	}
	free(tmp);
}
