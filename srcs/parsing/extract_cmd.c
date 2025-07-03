/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:55:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/07/03 03:25:41 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	update_quote_state(char c, char *quote)
{
	if (*quote == 0 && is_quote(c))
		*quote = c;
	else if (*quote == c)
		*quote = 0;
}

static int	skip_redirection_with_quotes(char *cmd, int i)
{
	char	quote;

	quote = 0;
	while (cmd[i] && (quote || !is_space(cmd[i])))
	{
		update_quote_state(cmd[i], &quote);
		i++;
	}
	return (i);
}

char	*extract_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*res;
	char	quote;

	(1) && (i = 0, j = 0);
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	quote = 0;
	while (cmd[i])
	{
		update_quote_state(cmd[i], &quote);
		if (!quote && is_redirection(cmd[i]))
		{
			i = skip_redirection(cmd, i);
			i = skip_redirection_with_quotes(cmd, i);
			while (is_space(cmd[i]))
				i++;
		}
		else
			res[j++] = cmd[i++];
	}
	res[j] = '\0';
	return (res);
}

void	handle_valid_var_expand(t_ms *ms, char *str, t_expand_state *st)
{
	char	*expanded;
	char	*tmp;

	if (ft_isalnum(str[st->i + 1])
		|| str[st->i + 1] == '?' || str[st->i + 1] == '_')
	{
		st->result = append_before(st->result, str, st->start, st->i);
		expanded = extract_and_expand_var(ms, str, &st->i);
		tmp = st->result;
		st->result = ft_strjoin(st->result, expanded);
		free(expanded);
		free(tmp);
		st->start = st->i + 1;
	}
}

BOOL	handle_digit_after_dollar(char *str, t_expand_state *st)
{
	if (is_digit(str[st->i + 1]))
	{
		st->result = append_before(st->result, str, st->start, st->i);
		st->i++;
		st->start = st->i + 1;
		return (TRUE);
	}
	return (FALSE);
}
