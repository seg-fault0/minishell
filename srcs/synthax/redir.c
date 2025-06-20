/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:17:19 by wimam             #+#    #+#             */
/*   Updated: 2025/06/20 03:23:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_quotes(char *s, int *i)
{
	char	quote;

	quote = s[*i];
	(*i)++;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (s[*i] == quote)
		(*i)++;
}

static BOOL	is_invalid_redir(char *s, int *i)
{
	if (s[*i + 1] == s[*i])
		(*i)++;
	(*i)++;
	while (s[*i] == ' ')
		(*i)++;
	return (!s[*i] || s[*i] == '<' || s[*i] == '>' || s[*i] == '|');
}

BOOL	open_redir_checker(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_quote(s[i]))
			skip_quotes(s, &i);
		else if (s[i] == '<' || s[i] == '>')
		{
			if (is_invalid_redir(s, &i))
				return (TRUE);
			if (is_quote(s[i]))
				skip_quotes(s, &i);
			else
				while (s[i] && s[i] != ' ' && s[i] != '<'
					&& s[i] != '>' && s[i++] != '|');
		}
		else
			i++;
	}
	return (FALSE);
}
