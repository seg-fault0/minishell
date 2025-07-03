/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/07/03 03:25:58 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*append_before(char *res, char *str, int start, int end)
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
	t_expand_state	st;

	(1) && (st.i = -1, st.start = 0, st.result = NULL);
	while (str[++st.i])
	{
		if (str[st.i] == '$' && (!skip_quotes
				|| !is_in_single_quotes(str, st.i)))
		{
			if (handle_digit_after_dollar(str, &st))
				continue ;
			handle_valid_var_expand(ms, str, &st);
		}
	}
	if (st.start < st.i)
		st.result = append_before(st.result, str, st.start, st.i);
	return (st.result);
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
