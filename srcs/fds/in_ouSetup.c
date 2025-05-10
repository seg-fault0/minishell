/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_ouSetup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:50:33 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 14:32:03 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_outfd(t_ms *ms)
{
	int	*fd;

	fd = &ms->fds.oufd;
	if (ms->fds.append_flag == TRUE)
		*fd = open(ms->parse.oustr, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd = open(ms->parse.oustr, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
		return (err_msg(ERR_OPEN_F));
}

void	setup_infd(t_ms *ms)
{
	if (ms->parse.delimiter)
		here_doc(ms);
	else
	{
		ms->fds.infd = open(ms->parse.instr, O_RDONLY);
		if (ms->fds.infd < 0)
			err_msg(ERR_OPEN_F);
	}
}
