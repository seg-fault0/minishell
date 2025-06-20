/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/19 19:13:32 by wimam            ###   ########.fr       */
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

static char	*extract_and_expand_var(t_ms *ms, char *str, int *i)
{
	char	*var_name;
	char	*var_value;
	int		start;
	int		len;

	start = *i + 1;
	len = 0;
	if (str[start] == '?')
	{
		var_value = ft_itoa(ms->cmd.last_exit_code);
		*i += 1;
		return (var_value);
	}
	while (str[start + len]
		&& (ft_isalnum(str[start + len]) || str[start + len] == '_'))
		len++;
	if (len == 0)
		return (ft_strdup("$"));
	var_name = ft_substr(str, start, len);
	var_value = get_env(ms->env, var_name);
	free(var_name);
	if (var_value)
		var_value = ft_strdup(var_value);
	else
		var_value = ft_strdup("");
	*i = start + len - 1;
	return (var_value);
}

static char	*append_text_before_dollar(char *result, char *str,
		int start, int end)
{
	char	*before;
	char	*new_result;

	before = ft_substr(str, start, end - start);
	if (!before)
		new_result = NULL;
	else
	{
		new_result = ft_strjoin(result, before);
		free(result);
	}
	return (free(before), new_result);
}

static char	*expand_line(t_ms *ms, char *str)
{
	char	*result;
	int		i;
	int		start;
	char	*expanded;
	char	*tmp;

	(1) && (i = -1, start = 0, result = NULL);
	while (str[++i])
	{
		if (str[i] == '$' && !is_in_single_quotes(str, i) && 
			(ft_isalnum(str[i + 1]) || str[i + 1] == '?' || str[i + 1] == '_'))
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
	if (start < i)
		result = append_text_before_dollar(result, str, start, i);
	return (result);
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
