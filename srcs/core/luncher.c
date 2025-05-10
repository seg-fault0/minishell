/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 15:41:42 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	ft_redline(t_ms *ms)
{
	char	*input;

	input = NULL;
	while (!input || !*input)
	{
		input = readline(PROMPT);
		if (!input)
			return (FALSE);
		if (*input)
			add_history(input);
	}
	ms->input = ft_strdup(input);
	return (TRUE);
}

void	reset_prompt(t_ms *ms)
{
	reset_fds(ms);
	free3(ms->parse.cmd, HEAP);
	free2(ms->cmd.paths, HEAP);
	free(ms->input);
	free(ms->cmd.pids);
	ms->cmd.cmd = NULL;
	ms->cmd.paths = NULL;
	ms->input = NULL;
	ms->cmd.pids = NULL;
}

void	ft_luncher(t_ms *ms)
{
	setup_signals();
	while (ft_redline(ms) == TRUE)
	{
		ft_parse(ms);
		setup_fds(ms);
		init_cmd(ms);
		ft_exe(ms);
		reset_prompt(ms);
	}
}
