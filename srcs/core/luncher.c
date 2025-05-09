/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 12:01:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_redline(t_ms *ms)
{
	ms->input = NULL;
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
	reset_fds(ms);
	free3(ms->parse.cmd, HEAP);
	free2(ms->cmd.paths, HEAP);
	ms->cmd.cmd = NULL;
	ms->cmd.paths = NULL;
}

void	ft_luncher(t_ms *ms)
{
	while (ft_redline(ms) == TRUE)
	{
		ft_parse(ms);
		setup_fds(ms);
		init_cmd(ms);
		ft_exe(ms);
		reset_prompt(ms);
	}
}
