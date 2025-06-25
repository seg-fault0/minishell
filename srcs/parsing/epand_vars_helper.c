/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epand_vars_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:34:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/25 10:41:59 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	is_in_single_quotes(const char *str, int pos)
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

BOOL	is_ft(const char *str)
{
	char	*equal_sign;

	equal_sign = ft_strchr(str, '=');
	if (!equal_sign)
		return (FALSE);
	if ((str < equal_sign && ft_strchr(str, '$') < equal_sign)
		&& ft_strchr(equal_sign + 1, '$'))
		return (TRUE);
	return (FALSE);
}

BOOL	is_in_assignment(const char *str, int pos)
{
	int	i;

	i = pos;
	while (i >= 0)
	{
		if (str[i] == '=' && !is_ft(str))
			return (TRUE);
		if (is_space(str[i]) || is_redirection(str[i]))
			return (FALSE);
		i--;
	}
	return (FALSE);
}

char	*wrap_if_needed(char *var_value, char *str, int i)
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

char	*extract_and_expand_var(t_ms *ms, char *str, int *i)
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
