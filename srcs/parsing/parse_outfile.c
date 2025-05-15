/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/15 15:05:03 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	fill_redirection_result(char *cmd, char *res, int i)
{
	int	j;

	j = 0;
	while (cmd[i])
	{
		if (!is_space(cmd[i]))
		{
			res[j++] = cmd[i];
		}
		i++;
	}
	res[j] = '\0';
}


char	*clean_redirection(char *cmd)
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

	ms->parse.oufiles = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	if (!ms->parse.oufiles)
		return ;
	i = 0;
	while (i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '>'))
		{
			redirect = clean_redirection(cmd);
			if (!redirect)
				return ;
			ms->parse.oufiles[i] = malloc(sizeof(char *) * 2);
			if (!ms->parse.oufiles[i])
				return ;
			ms->parse.oufiles[i][0] = redirect;
			ms->parse.oufiles[i][1] = NULL;
		}
		else
			ms->parse.oufiles[i] = NULL;
		i++;
	}
	ms->parse.oufiles[i] = NULL;
}
