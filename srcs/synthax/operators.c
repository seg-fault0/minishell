/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:35 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 14:54:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	ft_quote(char c, char *quote)
{
	if (c == '\'' || c == '\"')
	{
		if (*quote == 0)
			*quote = c;
		else if (*quote == c)
			*quote = 0;
		return (TRUE);
	}
	return (FALSE);
}

BOOL	ft_check_operator(char *s, int i)
{
	if ((s[i] == '<' && s[i + 1] == '<' && s[i + 2] == '<')
		|| (s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '>')
		|| (s[i] == '|' && s[i + 1] == '|'))
		return (TRUE);
	return (FALSE);
}

BOOL	operators_checker(char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		ft_quote(input[i], &quote);
		if (!quote && ft_check_operator(input, i))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
