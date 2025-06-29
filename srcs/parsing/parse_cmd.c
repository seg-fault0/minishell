/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:37 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/29 22:16:08 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_quotes(char *input, int *i)
{
	char	quote;
	char	*content;
	int		start;

	quote = input[*i];
	start = ++(*i);
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
	{
		content = ft_substr(input, start, *i - start);
		(*i)++;
		return (content);
	}
	return (NULL);
}

static char	*append_word_segment(char *input, int *i, char *word)
{
	char	*tmp;
	char	*new_word;
	int		start;

	if (input[*i] == '\'' || input[*i] == '"')
	{
		tmp = handle_quotes(input, i);
	}
	else
	{
		start = *i;
		while (input[*i] && !is_space(input[*i])
			&& !is_redirection(input[*i]) && !is_quote(input[*i]))
			(*i)++;
		tmp = ft_substr(input, start, *i - start);
	}
	new_word = ft_strjoin(word, tmp);
	free(word);
	free(tmp);
	return (new_word);
}

static char	*handle_word(char *input, int *i)
{
	char	*word;

	word = NULL;
	while (input[*i] && !is_space(input[*i]) && !is_redirection(input[*i]))
		word = append_word_segment(input, i, word);
	return (word);
}

char	**split_with_quotes(char *input)
{
	char	**result;
	int		i;
	int		j;

	result = ft_calloc(ft_strlen(input) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else
		{
			result[j] = handle_word(input, &i);
			if (result[j])
				j++;
		}
	}
	return (result);
}

void	parse_cmd(t_ms *ms)
{
	int		i;
	char	*clean;

	i = 0;
	while (i < ms->parse.cmd_nbr)
	{
		clean = extract_cmd(ms->parse.tmp2d[i]);
		ms->parse.cmd[i] = split_with_quotes(clean);
		i++;
		free(clean);
	}
	ms->parse.cmd[i] = NULL;
}
