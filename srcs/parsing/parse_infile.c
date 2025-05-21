/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:27 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/21 19:47:43 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_unquoted_input_redirs(char *cmd)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '<' && is_outside_quotes(cmd, &cmd[i]))
		{
			res[j++] = cmd[i];
			if (cmd[i + 1] == '<')
				res[j++] = cmd[++i];
			i++;
			while (cmd[i] && is_space(cmd[i]))
				i++;
			while (cmd[i] && !is_space(cmd[i]) && cmd[i] != '<')
				res[j++] = cmd[i++];
			res[j++] = ' ';
		}
		else
			i++;
	}
	res[j] = '\0';
	return (res);
}

static size_t	get_heredoc_flags(char *redirs)
{
	size_t	flags;
	int		count;
	int		i;

	flags = 0;
	count = 0;
	i = 0;
	while (redirs[i])
	{
		if (redirs[i] == '<')
		{
			if (redirs[i + 1] == '<')
			{
				flags |= (1 << count);
				i++;
			}
			count++;
		}
		i++;
	}
	return (flags);
}

void	parse_infile(t_ms *ms)
{
	int		i;
	char	*redirs;
	char	*clean_redirs;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		if (char_search(ms->parse.tmp2d[i], '<'))
		{
			redirs = extract_unquoted_input_redirs(ms->parse.tmp2d[i]);
			if (!redirs)
				return ;
			clean_redirs = ft_strjoin(redirs, " ");
			ms->fd.heredoc[i] = get_heredoc_flags(redirs);
			ms->parse.infiles[i] = ft_split(clean_redirs, ' ');
			free(redirs);
			free(clean_redirs);
		}
		else
			ms->parse.infiles[i] = NULL;
	}
	ms->parse.infiles[i] = NULL;
}
