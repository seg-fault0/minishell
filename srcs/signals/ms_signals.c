/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:09:32 by wimam             #+#    #+#             */
/*   Updated: 2025/06/26 16:32:16 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ms	*get_struct(void *arg)
{
	static t_ms	*ms;

	if (arg)
		ms = (t_ms *)arg;
	else
		return (ms);
	return (NULL);
}

static void	handle_sigint(int sig)
{
	t_ms	*ms;

	(void) sig;
	ms = get_struct(NULL);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	ms->cmd.last_exit_code = 130;
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	printf("%s", PROMPT);
}

void	minishell_signals(t_ms *ms)
{
	get_struct(ms);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
