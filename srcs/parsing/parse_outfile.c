/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/19 13:36:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*get_outfiles_str(char *cmd)
{
	char	*res;
	int		i;

	while (*cmd != '>')
		cmd++;
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!res)
		return (free(res), NULL);
	i = 0;
	while (*cmd)
	{
		if (is_space(*cmd) == FALSE)
			res[i++] = *cmd;
		cmd++;
	}
	res[i] = '\0';
	return (res);
}

void	parse_outfile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '>'))
		{
			redirect = get_outfiles_str(cmd);
			if (!redirect)
				return ;
			ms->parse.oufiles[i] = ft_split(redirect, '>');
			free(redirect);
		}
		else
			ms->parse.oufiles[i] = NULL;
	}
	ms->parse.oufiles[i] = NULL;
}
