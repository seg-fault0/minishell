/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:55:44 by wimam             #+#    #+#             */
/*   Updated: 2025/06/24 17:47:53 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	ft_allocator(t_ms *ms)
{
	int	size;
	int	i;

	size = sizeof(int) * ms->parse.cmd_nbr;
	ms->fd.out = malloc(size);
	if (!ms->fd.out)
		return (FALSE);
	ms->fd.in = malloc(size);
	if (!ms->fd.in)
		return (free(ms->fd.out), FALSE);
	i = -1;
	while (++i < ms->parse.cmd_nbr)
		ms->fd.in[i] = -2;
	i = -1;
	while (++i < ms->parse.cmd_nbr)
		ms->fd.out[i] = -2;
	return (TRUE);
}

void	fd_setup(t_ms *ms)
{
	if (ft_allocator(ms) == FALSE)
		return ;
	in_fd_opener(ms);
	if (sigint_trigered(ms) == TRUE)
		return ;
	ou_fd_opener(ms);
}
