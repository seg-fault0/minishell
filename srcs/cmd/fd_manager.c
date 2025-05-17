/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:56:07 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 11:56:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_manager(t_ms *ms, int rfd, int *pfd)
{
	if (dup2(rfd, STDIN) == -1)
		return (err_msg(ERR_DUP2_F), exit(0));
	if (ms->cmd.counter < ms->cmd.max_counter - 1)
	{
		if (dup2(pfd[1], STDOUT) == -1)
			return (err_msg(ERR_DUP2_F), exit(0));
	}
}
