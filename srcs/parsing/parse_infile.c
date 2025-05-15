/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:27 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/15 17:54:00 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	fill_redirection_result(char *cmd, char *res, int i)
{
	int	j;

	j = 0;
	while (cmd[i] && cmd[i] != '|')
	{
		if (cmd[i] == '<')
		{
			res[j++] = '<';
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
	while (cmd[i] && cmd[i] != '<')
		i++;
	if (!cmd[i])
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!res)
		return (NULL);
	fill_redirection_result(cmd, res, i);
	return (res);
}

void	parse_infile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	ms->parse.infiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	if (!ms->parse.infiles)
		return ;
	i = 0;
	while (i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '<'))
		{
			redirect = clean_redirection(cmd);
			if (!redirect)
				return ;
			ms->parse.infiles[i] = malloc(sizeof(char *) * 2);
			if (!ms->parse.infiles[i])
				return ;
			ms->parse.infiles[i][0] = redirect;
			ms->parse.infiles[i][1] = NULL;
		}
		else
			ms->parse.infiles[i] = NULL;
		i++;
	}
	ms->parse.infiles[i] = NULL;
}