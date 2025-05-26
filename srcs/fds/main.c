/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:55:44 by wimam             #+#    #+#             */
/*   Updated: 2025/05/26 11:54:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	ft_allocator(t_ms *ms)
{
	int	size;

	size = sizeof(int) * ms->parse.cmd_nbr;
	ms->fd.out = malloc(size);
	if (!ms->fd.out)
		return (FALSE);
	ms->fd.in = malloc(size);
	if (!ms->fd.in)
		return (free(ms->fd.out), FALSE);
	ft_memset(ms->fd.out, -1, size);
	ft_memset(ms->fd.in, -1, size);
	return (TRUE);
}

void	fd_setup(t_ms *ms)
{
	if (ft_allocator(ms) == FALSE)
		return ;
	in_fd_opener(ms);
	ou_fd_opener(ms);
}
