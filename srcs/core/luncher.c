/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/06/27 00:30:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_readline(t_ms *ms)
{
	while (!ms->input || !*ms->input)
	{
		ms->input = readline(PROMPT);
		if (!ms->input)
			return (printf("exit\n"), FALSE);
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
	minishell_signals();
	while (ft_readline(ms) == TRUE)
	{
		if (synthax_checker(ms->input) == TRUE)
		{
			ft_parse(ms);
			fd_setup(ms);
			if (sigint_trigered(ms) == FALSE)
				ft_exe(ms);
		}
		else
			ms->cmd.last_exit_code = 2;
		reset_prompt(ms);
	}
}
