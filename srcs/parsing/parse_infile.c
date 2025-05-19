/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:27 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/19 13:24:07 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*get_infiles_str(char *cmd)
{
	char	*infiles;
	int		i;
	int		j;

	infiles = malloc(ft_strlen(cmd) + 1);
	if (!infiles)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<')
		{
			infiles[j++] = '<';
			i++;
			while (is_space(cmd[i]))
				i++;
			while (cmd[i] && !is_space(cmd[i])
				&& cmd[i] != '<' && cmd[i] != '>')
				infiles[j++] = cmd[i++];
		}
		else
			i++;
	}
	return (infiles[j] = '\0', infiles);
}

void	parse_infile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '<'))
		{
			redirect = get_infiles_str(cmd);
			if (!redirect)
				return ;
			ms->parse.infiles[i] = ft_split(redirect, '<');
			free(redirect);
		}
		else
			ms->parse.infiles[i] = NULL;
	}
	ms->parse.infiles[i] = NULL;
}
