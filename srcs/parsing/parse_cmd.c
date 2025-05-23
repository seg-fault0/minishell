/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:37 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/23 18:58:07 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_quoted_content(char *cmd, int *i, char quote)
{
	int		start;
	char	*content;

	start = *i + 1;
	(*i)++;
	while (cmd[*i] && cmd[*i] != quote)
	{
		if (cmd[*i])
			(*i)++;
	}
	if (cmd[*i] == quote)
	{
		content = ft_substr(cmd, start, *i - start);
		(*i)++;
		return (content);
	}
	return (NULL);
}

static char	*extract_regular_word(char *cmd, int *i)
{
	int	start;

	start = *i;
	while (cmd[*i] && !is_space(cmd[*i])
		&&!is_redirection(cmd[*i]) && !is_quote(cmd[*i]))
	{
		if (cmd[*i])
			(*i)++;
	}
	if (*i > start)
		return (ft_substr(cmd, start, *i - start));
	return (NULL);
}

static char	**split_outside_quotes(char *cmd)
{
	char	**words;
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	words = malloc((ft_strlen(cmd) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (cmd[i])
	{
		if (is_quote(cmd[i]))
		{
			words[word_count] = extract_quoted_content(cmd, &i, cmd[i]);
			if (words[word_count])
				word_count++;
		}
		else if (is_redirection(cmd[i]))
			i = skip_redirection(cmd, i);
		else if (!is_space(cmd[i]))
		{
			words[word_count] = extract_regular_word(cmd, &i);
			if (words[word_count])
				word_count++;
		}
		else
			i++;
	}
	words[word_count] = NULL;
	return (words);
}

void	parse_cmd(t_ms *ms)
{
	int		i;
	char	*clean;

	i = 0;
	while (i < ms->parse.cmd_nbr)
	{
		clean = extract_cmd(ms->parse.tmp2d[i]);
		ms->parse.cmd[i] = split_outside_quotes(clean);
		i++;
	}
	free(clean);
	ms->parse.cmd[i] = NULL;
}
