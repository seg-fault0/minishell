/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synthax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:26:01 by wimam             #+#    #+#             */
/*   Updated: 2025/05/11 11:53:51 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define UNCLOSED_QUOTES 1

void	synthax_err_msg(int msg)
{
	if (msg == UNCLOSED_QUOTES)
		ft_putstr_fd("synthax error : unclosed quotes\n", STDERR);
}

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

BOOL	synthax_checker(char *input)
{
	if (quotes_checker(input) == TRUE)
		return (synthax_err_msg(UNCLOSED_QUOTES), FALSE);
	return (TRUE);
}
