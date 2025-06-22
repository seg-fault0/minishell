/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:38:27 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 15:23:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(t_ms *ms)
{
	char	*cmd;
	int		counter;

	counter = ms->cmd.counter;
	cmd = ms->cmd.cmd[counter][0];
	if (access(cmd, F_OK) != 0)
		return (err_msg(ERR_CMD_NF), 127);
	if (access(cmd, X_OK) != 0)
		return (126);
	if (is_dir(cmd) == TRUE)
		return (err_msg(ERR_THIS_IS_DIR), 126);
	if (ms->cmd.cmd[counter][1] != NULL
		&& access(ms->cmd.cmd[counter][1], F_OK) != 0)
		return (2);
	return (err_msg(ERR_CMD_NF), 127);
}
