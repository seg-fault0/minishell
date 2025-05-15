/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:59 by wimam             #+#    #+#             */
/*   Updated: 2025/05/15 17:57:15 by zogrir           ###   ########.fr       */
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
	
	free3(ms->parse.cmd, HEAP);
	free3(ms->parse.infiles, HEAP);
	free3(ms->parse.oufiles, HEAP);
	ms->parse.cmd = NULL;
	ms->parse.oufiles = NULL;
	ms->parse.oufiles = NULL;
}

void	print_parsed(t_ms *ms)
{
	for (int i = 0; i < ms->parse.cmd_nbr; i++)
	{
		if (ms->parse.cmd && ms->parse.cmd[i])
		{
			for (int j = 0; ms->parse.cmd[i][j]; j++)
				printf("infile[%d][%d] = %s\n", i, j, ms->parse.cmd[i][j]);
		}
		else
			printf("cmd[%d][0] = NULL\n", i);
		printf("\n");
	}
	
	printf("---------------------------------------\n");
	
	for (int i = 0; i < ms->parse.cmd_nbr; i++)
	{
		if (ms->parse.infiles && ms->parse.infiles[i])
		{
			for (int j = 0; ms->parse.infiles[i][j]; j++)
				printf("infile[%d][%d] = %s\n", i, j, ms->parse.infiles[i][j]);
		}
		else
			printf("infile[%d][0] = NULL\n", i);
		printf("\n");
	}
	printf("---------------------------------------\n");

	for (int i = 0; i < ms->parse.cmd_nbr; i++)
	{
		if (ms->parse.oufiles && ms->parse.oufiles[i])
		{
			for (int j = 0; ms->parse.oufiles[i][j]; j++)
				printf("outfiles[%d][%d] = %s\n", i, j, ms->parse.oufiles[i][j]);
		}
		else
			printf("outfiles[%d][0] = NULL\n", i);
		printf("\n");
	}
	printf("---------------------------------------\n");
}

void	ft_luncher(t_ms *ms)
{
	setup_signals();
	while (ft_redline(ms) == TRUE)
	{
		if (synthax_checker(ms->input) == TRUE)
		{
			ft_parse(ms);

			print_parsed(ms);
			// setup_fds(ms);
			// init_cmd(ms);
			// ft_exe(ms);
		}
		reset_prompt(ms);
	}
}
