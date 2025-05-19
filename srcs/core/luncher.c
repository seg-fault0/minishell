/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 13:12:46 by wimam            ###   ########.fr       */
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
			init_cmd(ms);
			ft_exe(ms);
		}
		reset_prompt(ms);
	}
}
