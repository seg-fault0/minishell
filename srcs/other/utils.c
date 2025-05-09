/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:07:36 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 14:56:23 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int *fd)
{
	ft_close (fd[0]);
	ft_close (fd[1]);
}

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (is_space(str[i]) == TRUE)
		i++;
	return (i);
}
