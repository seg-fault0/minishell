/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oufd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:57 by wimam             #+#    #+#             */
/*   Updated: 2025/05/26 10:35:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_outfiles_opener(char	**files, int append_code)
{
	char	*filename;
	int		fd;
	int		i;

	i = 0;
	while (files[i])
	{
		filename = files[i];
		if ((append_code >> i) & 1)
			fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (err_msg(ERR_OPEN_F), -1);
		if (!files[i + 1])
			return (fd);
		else
			ft_close(fd);
		i++;
	}
	return (-1);
}

void	ou_fd_opener(t_ms *ms)
{
	int		i;
	int		fd;

	if (!ms->parse.oufiles)
		return ;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		if (ms->parse.oufiles[i])
		{
			fd = cmd_outfiles_opener(ms->parse.oufiles[i], ms->fd.append[i]);
			ms->fd.out[i] = fd;
		}
	}
}
