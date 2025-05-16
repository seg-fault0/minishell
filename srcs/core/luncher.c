/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/16 18:01:40 by zogrir           ###   ########.fr       */
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
	free2(ms->cmd.paths, HEAP);
	free(ms->input);
	free(ms->cmd.pids);
	ms->cmd.paths = NULL;
	ms->cmd.cmd = NULL;
	ms->input = NULL;
	ms->cmd.pids = NULL;
	free3size(ms->parse.cmd, ms->parse.cmd_nbr);
	free3size(ms->parse.infiles, ms->parse.cmd_nbr);
	free3size(ms->parse.oufiles, ms->parse.cmd_nbr);
	ms->parse.cmd = NULL;
	ms->parse.infiles = NULL;
	ms->parse.oufiles = NULL;
}

void	ft_luncher(t_ms *ms)
{
	setup_signals();
	while (ft_redline(ms) == TRUE)
	{
		if (synthax_checker(ms->input) == TRUE)
		{
			ft_parse(ms);
			init_cmd(ms);
			ft_exe(ms);
		}
		reset_prompt(ms);
	}
}
