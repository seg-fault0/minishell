/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/24 19:43:51 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static int	is_in_single_quotes(const char *str, int pos)
{
	int	i;
	int	squote;
	int	dquote;

	squote = 0;
	dquote = 0;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && dquote == 0)
			squote = !squote;
		else if (str[i] == '"' && squote == 0)
			dquote = !dquote;
		i++;
	}
	return (squote);
}

static BOOL	is_in_assignment(const char *str, int pos)
{
	int	i;

	i = pos;
	while (i >= 0)
	{
		if (str[i] == '=')
			return (TRUE);
		if (is_space(str[i]) || is_redirection(str[i]))
			return (FALSE);
		i--;
	}
	return (FALSE);
}

static char	*wrap_if_needed(char *var_value, char *str, int i)
{
	char	*quoted;
	char	*final;

	if (!var_value)
		return (ft_strdup(""));
	if (is_in_assignment(str, i) && ft_strchr(var_value, ' '))
	{
		quoted = ft_strjoin("\"", var_value);
		final = ft_strjoin(quoted, "\"");
		free(quoted);
		return (final);
	}
	return (ft_strdup(var_value));
}

static char	*extract_and_expand_var(t_ms *ms, char *str, int *i)
{
	char	*var_name;
	char	*var_value;
	int		start;
	int		len;

	start = *i + 1;
	if (str[start] == '?')
		return (*i += 1, ft_itoa(ms->cmd.last_exit_code));
	len = 0;
	while (str[start + len] && (ft_isalnum(str[start + len])
			|| str[start + len] == '_'))
		len++;
	if (len == 0)
		return (ft_strdup("$"));
	var_name = ft_substr(str, start, len);
	var_value = get_env(ms->env, var_name);
	free(var_name);
	var_value = wrap_if_needed(var_value, str, *i);
	*i = start + len - 1;
	return (var_value);
}

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
		if ((ft_isalnum(str[i + 1]) || str[i + 1] == '?' || str[i + 1] == '_')
			&& str[i] == '$' && (!skip_quotes || !is_in_single_quotes(str, i)))
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
