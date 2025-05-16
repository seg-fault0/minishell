/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/16 16:06:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	fill_redirection_result(char *cmd, char *res, int i)
{
	int	j;

	j = 0;
	while (cmd[i] && cmd[i] != '|')
	{
		if (cmd[i] == '>')
		{
			res[j++] = '>';
			i++;
			while (cmd[i] && is_space(cmd[i]))
				i++;
			while (cmd[i] && !is_space(cmd[i])
				&& cmd[i] != '>' && cmd[i] != '<' && cmd[i] != '|')
			{
				res[j++] = cmd[i];
				i++;
			}
		}
		else
			i++;
	}
	res[j] = '\0';
}

static char	*clean_redirection(char *cmd)
{
	int		i;
	char	*res;

	i = 0;
	while (cmd[i] && cmd[i] != '>')
		i++;
	if (!cmd[i])
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!res)
		return (NULL);
	fill_redirection_result(cmd, res, i);
	return (res);
}

void	parse_outfile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	i = 0;
	if (ms->parse.oufiles)
		free3size(ms->parse.oufiles, ms->parse.cmd_nbr);
	ms->parse.oufiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	if (!ms->parse.oufiles)
		return ;
	while (i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '>'))
		{
			redirect = clean_redirection(cmd);
			if (!redirect)
				return ;
			ms->parse.oufiles[i] = ft_split(redirect, '>');
			free(redirect);
		}
		else
			ms->parse.oufiles[i] = NULL;
		i++;
	}
	ms->parse.oufiles[i] = NULL;
}
