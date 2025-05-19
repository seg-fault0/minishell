/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 21:50:01 by zogrir           ###   ########.fr       */
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
			expand_vars(ms);
			fd_setup(ms);
			init_cmd(ms);
			ft_exe(ms);
			printf("%s\n", ms->parse.tmp2d[0]);
		}
		reset_prompt(ms);
	}
}
