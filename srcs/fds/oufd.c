/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oufd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:57 by wimam             #+#    #+#             */
/*   Updated: 2025/06/27 01:39:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_fd(t_ms *ms, char *filename, int i, int j)
{
	int	fd;

	if ((ms->fd.append[i] >> j) & 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

void	handle_outfile(t_ms *ms, char **arr, int i)
{
	int		j;
	int		fd;
	char	*filename;

	j = -1;
	while (arr && arr[++j])
	{
		filename = arr[j];
		if (ft_strcmp(filename, "/dev/stdout") == FALSE)
		{
			fd = get_fd(ms, filename, i, j);
			if (fd == -1)
			{
				ft_putstr_fd("permission denied\n", STDERR);
				ms->cmd.cur_exit_code = 1;
				ms->fd.out[i] = fd;
				break ;
			}
			if (arr[j + 1] == NULL || stdout_file_checker(&arr[j + 1]) == TRUE)
				return (ms->fd.out[i] = fd, (void) 0);
			else
				ft_close(fd);
		}
	}
}

void	ou_fd_opener(t_ms *ms)
{
	int	i;

	if (!ms->parse.oufiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
		handle_outfile(ms, ms->parse.oufiles[i], i);
}
