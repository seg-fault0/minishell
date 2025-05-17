/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:54:24 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 13:23:52 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exe(t_ms *ms)
{
	char	*first_cmd;

	if (!ms->input || !*ms->input)
		return ;
	first_cmd = ms->cmd.cmd[0][0];
	if (is_main_process_exe(first_cmd) == TRUE)
		builtin_exe(ms, first_cmd);
	else
		ft_start(ms, ms->fd.in[0]);
	ms->cmd.last_exit_code = WEXITSTATUS(ms->cmd.cur_exit_code);
}
