/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oufd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:57 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 10:10:25 by wimam            ###   ########.fr       */
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
	while (++i < ms->parse.cmd_nbr)
	{
		j = -1;
		while (ms->parse.oufiles[i][++j])
		{
			filename = ms->parse.oufiles[i][j];
			fd = open(filename, O_WRONLY | O_CREAT);
			ft_close(fd);
		}
	}
}
