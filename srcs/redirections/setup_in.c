/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:32:07 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 12:08:51 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_infd(t_ms *ms)
{
	ms->fds.infd = open(ms->fds.instr, O_RDONLY);
	if (ms->fds.infd < 0)
		err_msg(ERR_OPEN_F);
}
