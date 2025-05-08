/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 10:23:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_redline(t_ms *ms)
{
	ms->input = readline(PROMPT);
	if (!ms->input)
		return (FALSE);
	add_history(ms->input);
	return (TRUE);
}

void	reset_prompt(t_ms *ms)
{
	free3(ms->parse.cmd, HEAP);
}

void	ft_luncher(t_ms *ms)
{
	while (ft_redline(ms) == TRUE)
	{
		ft_parse(ms);
		init_cmd(ms);
		ft_exe(ms);
		reset_prompt(ms);
	}
}
