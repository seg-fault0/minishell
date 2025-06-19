/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oufd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:57 by wimam             #+#    #+#             */
/*   Updated: 2025/06/19 20:07:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ou_fd_opener(t_ms *ms)
{
	int		i;
	int		j;
	int		fd;
	char	*filename;

	if (!ms->parse.oufiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		j = -1;
		while (ms->parse.oufiles[i] && ms->parse.oufiles[i][++j])
		{
			filename = ms->parse.oufiles[i][j];
			if ((ms->fd.append[i] >> j) & 1)
				fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
			else
				fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
			{
				ft_putstr_fd("permission denied\n", STDERR);
				ms->fd.out[i] = fd;
				break ;
			}
			if (ms->parse.oufiles[i][j + 1] == NULL)
				ms->fd.out[i] = fd;
			else
				ft_close(fd);
		}
	}
}	
