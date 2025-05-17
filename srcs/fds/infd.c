/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:10:28 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 13:21:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_fd_opener(t_ms *ms)
{
	char	*filename;
	int		i;
	int		j;
	int		fd;

	i = -1;
	if (!ms->parse.infiles)
		return ;
	while (++i < ms->parse.cmd_nbr)
	{
		j = -1;
		while (ms->parse.infiles[i] && ms->parse.infiles[i][j])
		{
			filename = ms->parse.infiles[i][j];
			fd = open(filename, O_RDONLY);
			if (!ms->parse.infiles[i][j + 1])
				ms->fd.in[i] = fd;
			else
				ft_close(fd);
			j++;
		}
	}
}
