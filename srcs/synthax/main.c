/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:26:01 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 13:40:34 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define OPEN_QUOTES 1
#define OPEN_PIPE 2

void	synthax_err_msg(int msg)
{
	if (msg == OPEN_QUOTES)
		ft_putstr_fd("synthax error : unclosed quotes\n", STDERR);
	else if (msg == OPEN_PIPE)
		ft_putstr_fd("synthax error : unclosed pipes\n", STDERR);
}

BOOL	synthax_checker(char *input)
{
	if (open_quotes_checker(input) == TRUE)
		return (synthax_err_msg(OPEN_QUOTES), FALSE);
	if (open_pipe_checker(input) == TRUE)
		return (synthax_err_msg(OPEN_PIPE), FALSE);
	return (TRUE);
}
