/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:10:28 by wimam             #+#    #+#             */
/*   Updated: 2025/06/26 22:54:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_infile(t_ms *ms, int i)
{
	int	j;
	int	fd;

	j = -1;
	while (ms->parse.infiles[i] && ms->parse.infiles[i][++j])
	{
		if ((ms->fd.heredoc[i] >> j) & 1)
			fd = here_doc(ms, ms->parse.infiles[i][j]);
		else
			fd = open(ms->parse.infiles[i][j], O_RDONLY);
		if (fd == -130)
			return (ms->fd.in[i] = fd, (void) 0);
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

void	in_fd_opener(t_ms *ms)
{
	int	i;

	if (!ms->parse.infiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		handle_infile(ms, i);
		if (ms->fd.in[i] == -130)
			return ;
	}
	ms->cmd.cur_exit_code = 0;
}
