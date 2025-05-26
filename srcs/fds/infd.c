/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:10:28 by wimam             #+#    #+#             */
/*   Updated: 2025/05/26 13:12:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_fd_opener(t_ms *ms)
{
	int		i;
	int		j;

	if (!ms->parse.infiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		j = 0;
		while (ms->parse.infiles[i] && ms->parse.infiles[i][j])
			j++;
		if (j > 0)
		{
			ms->fd.in[i] = open(ms->parse.infiles[i][j - 1], O_RDONLY);
			if (ms->fd.in[i] == -1)
				err_msg(ERR_OPEN_F);
		}
	}
}
