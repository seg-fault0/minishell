/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 11:33:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL ft_redline()
{
	const char *input;

	input = readline(PROMPT);
	if (!input)
		return (FALSE);
	add_history(input);
	return (TRUE);
}

void	ft_luncher(t_ms *ms)
{
	(void) ms;
	while (ft_redline() == TRUE);
}