/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:01:39 by wimam             #+#    #+#             */
/*   Updated: 2025/07/06 05:03:12 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait(t_ms *ms)
{
	int		i;
	int		id;
	int		status;
	BOOL	new_line;

	new_line = FALSE;
	i = -1;
	while (++i < ms->cmd.counter)
	{
		id = ms->cmd.pids[i];
		waitpid(id, &status, 0);
		if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGINT && new_line == FALSE)
			{
				write(STDOUT, "\n", 1);
				new_line = TRUE;
			}
			if (i == ms->cmd.counter - 1)
				return (ms->cmd.cur_exit_code = 130, (void) 0);
		}
		ms->cmd.cur_exit_code = status;
	}
	ms->cmd.cur_exit_code = WEXITSTATUS(ms->cmd.cur_exit_code);
}
