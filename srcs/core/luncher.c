/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/18 15:19:48 by zogrir           ###   ########.fr       */
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
			expand_vars(ms);
			fd_setup(ms);
			init_cmd(ms);
			ft_exe(ms);
			printf("%s\n", ms->parse.tmp2d[0]);
		}
		reset_prompt(ms);
	}
}
