/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 12:02:42 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL ft_redline(t_ms *ms)
{
	const char *input;

	input = readline(PROMPT);
	if (!input)
		return (FALSE);
	free(ms->input);
	ms->input = ft_strdup(input);
	add_history(input);
	return (TRUE);
}

void	ft_luncher(t_ms *ms)
{
	while (ft_redline(ms) == TRUE);
}