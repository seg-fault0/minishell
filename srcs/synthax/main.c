/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:26:01 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 14:45:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define OPEN_QUOTES "synthax error : unclosed quotes\n"
#define OPEN_PIPE "synthax error : unclosed pipes\n"
#define INVALID_OP "synthax error : invalid operator\n"

BOOL	synthax_checker(char *input)
{
	if (open_quotes_checker(input) == TRUE)
		return (ft_putstr_fd(OPEN_QUOTES, STDERR), FALSE);
	if (operators_checker(input) == TRUE)
		return (ft_putstr_fd(INVALID_OP, STDERR), FALSE);
	if (open_pipe_checker(input) == TRUE)
		return (ft_putstr_fd(OPEN_PIPE, STDERR), FALSE);
	return (TRUE);
}	
