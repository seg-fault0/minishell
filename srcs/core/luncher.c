/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 09:36:22 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_redline(t_ms *ms)
{
	while (!ms->input || !*ms->input)
	{
		ms->input = readline(PROMPT);
		if (!ms->input)
			return (FALSE);
		if (*ms->input)
			add_history(ms->input);
	}
	return (TRUE);
}

void	reset_prompt(t_ms *ms)
{
	parse_reseter(ms);
	cmd_reseter(ms);
	fd_reseter(ms);
	free(ms->input);
	ms->input = NULL;
}

void	ft_luncher(t_ms *ms)
{
	setup_signals();
	while (ft_redline(ms) == TRUE)
	{
		if (synthax_checker(ms->input) == TRUE)
		{
			ft_parse(ms);
			fd_setup(ms);
			ft_exe(ms);
		}
		reset_prompt(ms);
	}
}
