/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:38 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 11:05:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	chdir_synthax(t_ms *ms)
{
	if (ms->cmd.cmd[ms->cmd.counter][1] == NULL)
		return (TRUE);
	if (ms->cmd.cmd[ms->cmd.counter][2] != NULL)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR), FALSE);
	return (TRUE);
}

void	ft_chdir(t_ms *ms)
{
	char	*path;
	int		counter;

	counter = ms->cmd.counter;
	if (chdir_synthax(ms) == FALSE)
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	if (ms->cmd.cmd[counter][1] == NULL)
		path = get_env(ms->env, "HOME");
	else
		path = ms->cmd.cmd[counter][1];
	if (!path)
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	if (chdir(path) == -1)
	{
		ms->cmd.cur_exit_code = 1;
		err_msg(ERR_CHDIR_F);
	}
}
