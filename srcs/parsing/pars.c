/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/15 14:38:37 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ft_parse(t_ms *ms)
{
    char 	*tmp;
	int		i;

	i = 0;
    tmp = ft_strdup(ms->input);
    if (!tmp)
        return ;
    ms->parse.cmd_nbr = pipe_counter(ms->input, '|') + 1;
    ms->parse.tmp2d = quote_protect(tmp, strlen(tmp) + 1);
	if (char_search(ms->parse.tmp2d[i] , '>') == TRUE)
		parse_outfile(ms);

	for (int i = 0; i < ms->parse.cmd_nbr; i++)
	{
		if (ms->parse.oufiles && ms->parse.oufiles[i])
		{
			for (int j = 0; ms->parse.oufiles[i][j]; j++)
				printf("outfiles[%d][%d] = %s\n", i, j, ms->parse.oufiles[i][j]);
		}
		else
			printf("outfiles[%d][0] = NULL\n", i);
		printf("\n");
	}
		
    free(tmp);
}

