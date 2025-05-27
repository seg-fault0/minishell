/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:38:27 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 09:38:33 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(t_ms *ms)
{
	int	counter;

	counter = ms->cmd.counter;
	if (access(ms->cmd.cmd[counter][0], X_OK) != 0)
		return (127);
	if (access(ms->cmd.cmd[counter][1], F_OK) == 0)
		return (2);
	return (0);
}
