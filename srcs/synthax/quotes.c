/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:39:10 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 09:39:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	quotes_checker(char *input)
{
	BOOL	open_flag;
	char	c;

	open_flag = FALSE;
	c = 0;
	while (*input)
	{
		if ((*input == '\'' || *input == '\"') && open_flag == FALSE)
		{
			c = *input;
			open_flag = TRUE;
		}
		else if (c != 0 && c == *input)
			open_flag = FALSE;
		input++;
	}
	return (open_flag);
}
