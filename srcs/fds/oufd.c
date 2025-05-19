/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oufd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:57 by wimam             #+#    #+#             */
/*   Updated: 2025/05/19 11:58:46 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ou_fd_opener(t_ms *ms)
{
	char	*filename;
	int		i;
	int		j;
	int		fd;

	i = -1;
	if (!ms->parse.oufiles)
		return ;
	while (++i < ms->parse.cmd_nbr)
	{
		j = 0;
		while (ms->parse.oufiles[i] && ms->parse.oufiles[i][j])
		{
			filename = ms->parse.oufiles[i][j];
			fd = open(filename, O_WRONLY | O_CREAT);
			if (!ms->parse.oufiles[i][j + 1])
				ms->fd.out[i] = fd;
			else
				ft_close(fd);
			j++;
		}
	}
}
