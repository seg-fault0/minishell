/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/24 10:18:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static int	is_in_single_quotes(const char *str, int pos)
{
	int		i;
	int		squote;
	int		dquote;

	squote = 0;
	dquote = 0;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && dquote == 0)
			squote = !squote;
		else if (str[i] == '\"' && squote == 0)
			dquote = !dquote;
		i++;
	}
	return (squote);
}

static char	*extract_and_expand_var(t_ms *ms, char **str, int *i)
{
	char	*var_name;
	char	*var_value;
	int		start;
	int		len;

	start = *i + 1;
	len = 0;
	while (ft_isalnum((*str)[start + len]))
		len++;
	var_name = ft_substr(*str, start, len);
	var_value = get_env(ms->env, var_name);
	free(var_name);
	*str += start + len;
	return (ft_strdup(var_value));
}

static char	*append_text_before_dollar(char *result, char *str, int i)
{
	char	*before;
	char	*new_result;

	before = ft_substr(str, 0, i);
	new_result = ft_strjoin(result, before);
	return (free(result), free(before), new_result);
}

static char	*expand_line(t_ms *ms, char *str)
{
	char	*result;
	int		i;
	char	*temp;
	char	*expanded;

	i = 0;
	result = NULL;
	while (str[i])
	{
		if (str[i] == '$' && !is_in_single_quotes(str, i)
			&& ft_isalnum(str[i + 1]))
		{
			result = append_text_before_dollar(result, str, i);
			expanded = extract_and_expand_var(ms, &str, &i);
			temp = result;
			result = ft_strjoin(temp, expanded);
			free(expanded);
			free(temp);
		}
		else
			i++;
	}
	temp = result;
	result = ft_strjoin(result, str);
	return (free(temp), result);
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
