/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/07/02 18:39:39 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*append_text_before_dollar(char *res, char *str, int start, int end)
{
	char	*before;
	char	*new_res;

	before = ft_substr(str, start, end - start);
	if (!before)
		return (NULL);
	new_res = ft_strjoin(res, before);
	free(res);
	free(before);
	return (new_res);
}

static char	*expand_generic(t_ms *ms, char *str, BOOL skip_quotes)
{
	int		i;
	int		start;
	char	*result;
	char	*expanded;
	char	*tmp;

	(1) && (i = -1, start = 0, result = NULL);
	while (str[++i])
	{
		if (str[i] == '$' && (!skip_quotes || !is_in_single_quotes(str, i)))
		{
			if (is_digit(str[i + 1]))
			{
				result = append_text_before_dollar(result, str, start, i);
				i++;
				start = i + 1;
				continue;
			}
			if ((ft_isalnum(str[i + 1]) || str[i + 1] == '?' || str[i + 1] == '_'))
			{
				result = append_text_before_dollar(result, str, start, i);
				expanded = extract_and_expand_var(ms, str, &i);
				tmp = result;
				result = ft_strjoin(result, expanded);
				free(expanded);
				free(tmp);
				start = i + 1;
			}
		}
	}
	if (start < i)
		result = append_text_before_dollar(result, str, start, i);
	return (result);
}

static char	*expand_line(t_ms *ms, char *str)
{
	return (expand_generic(ms, str, TRUE));
}

char	*expand_line_heredoc(t_ms *ms, char *str)
{
	return (expand_generic(ms, str, FALSE));
}

void	expand_vars(t_ms *ms)
{
	int		i;
	char	*expanded;

	i = -1;
	while (ms->parse.tmp2d[++i])
	{	
		if (ft_strchr(ms->parse.tmp2d[i], '$'))
		{	
			expanded = expand_line(ms, ms->parse.tmp2d[i]);
			free(ms->parse.tmp2d[i]);
			ms->parse.tmp2d[i] = expanded;
		}
	}
}
