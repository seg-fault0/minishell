/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:27 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/27 10:16:43 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*get_infiles_str(char *cmd)
{
	char	*infiles;
	int		i;
	int		j;
	char	quote;

	infiles = malloc(ft_strlen(cmd) + 1);
	if (!infiles)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
		{
			quote = cmd[i++];
			while (cmd[i] && cmd[i] != quote)
				i++;
			if (cmd[i] == quote)
				i++;
		}
		else if (cmd[i] == '<')
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

static size_t	heredoc_scanner(char *files_str)
{
	int	file;
	int	ret;
	int	i;

	file = 0;
	ret = 0;
	i = 0;
	while (files_str[i])
	{
		if (files_str[i] == '<')
		{
			if (files_str[i + 1] == '<')
			{
				ret |= (1 << file);
				i++;
			}
			file++;
		}
		i++;
	}
	return (ret);
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
			ms->fd.heredoc[i] = heredoc_scanner(redirect);
			ms->parse.infiles[i] = ft_split(redirect, '<');
			free(redirect);
		}
		else
			ms->parse.infiles[i] = NULL;
	}
	ms->parse.infiles[i] = NULL;
}
