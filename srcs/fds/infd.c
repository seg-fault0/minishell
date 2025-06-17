/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:10:28 by wimam             #+#    #+#             */
/*   Updated: 2025/06/17 16:30:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_fd_opener(t_ms *ms)
{
	int		i;
	int		j;
	int		fd;

	if (!ms->parse.infiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		j = -1;
		while (ms->parse.infiles[i] && ms->parse.infiles[i][++j])
		{
			if ((ms->fd.heredoc[i] >> j) & 1)
				fd = here_doc(ms->parse.infiles[i][j]);
			else
				fd = open(ms->parse.infiles[i][j], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("no such file or directory\n", STDERR);
				ms->fd.in[i] = fd;
				break ;
			}
			if (ms->parse.infiles[i][j + 1] == NULL)
				ms->fd.in[i] = fd;
			else
				ft_close(fd);
		}
	}
}
