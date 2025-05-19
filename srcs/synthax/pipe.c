/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:38:00 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 13:46:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		else if (input[i] == '|' && !in_quotes)
		{
			while (input[++i] == ' ')
				i++;
			if (input[i] == '|' || input[i] == '\0')
				return (TRUE);
		}
	}
	return (FALSE);
}
