/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 14:31:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_cmd(t_ms *ms)
{
	char	**tmp_cmd;
	int		i;

	ms->parse.cmd = malloc((ms->parse.cmd_nbr + 1) * sizeof(char **));
	if (!ms->parse.cmd)
		return ;
	tmp_cmd = ft_split(ms->input, '|');
	if (!tmp_cmd)
		return (free(ms->parse.cmd));
	i = -1;
	while (tmp_cmd[++i])
		ms->parse.cmd[i] = ft_split(tmp_cmd[i], ' ');
	ms->parse.cmd[i] = NULL;
	free2(tmp_cmd, HEAP);
}

void	ft_parse(t_ms *ms)
{
	ms->parse.cmd_nbr = char_counter(ms->input, '|') + 1;
	if (char_search(ms->input, '>') == TRUE)
		parse_outfile(ms);
	parse_cmd(ms);
}
