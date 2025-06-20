/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:38:00 by wimam             #+#    #+#             */
/*   Updated: 2025/06/20 09:40:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	is_invalid_pipe(char *input, int i)
{
	int	left;
	int	right;

	left = i - 1;
	right = i + 1;
	while (left >= 0 && input[left] == ' ')
		left--;
	if (left < 0)
		return (TRUE);
	while (input[right] == ' ')
		right++;
	if (input[right] == '\0' || input[right] == '|')
		return (TRUE);
	return (FALSE);
}

BOOL	open_pipe_checker(char *input)
{
	BOOL	in_quotes;
	char	quote_char;
	int		i;

	in_quotes = FALSE;
	quote_char = '\0';
	i = -1;
	while (input[++i])
	{
		if (is_quote(input[i]) && !in_quotes)
		{
			in_quotes = TRUE;
			quote_char = input[i];
		}
		else if (input[i] == quote_char)
			in_quotes = FALSE;
		else if (input[i] == '|' && !in_quotes && is_invalid_pipe(input, i))
			return (TRUE);
	}
	return (FALSE);
}
