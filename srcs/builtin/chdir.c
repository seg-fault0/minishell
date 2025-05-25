/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:38 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 16:43:44 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(t_ms *ms)
{
	char	*path;
	int		counter;

	counter = ms->cmd.counter;
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
