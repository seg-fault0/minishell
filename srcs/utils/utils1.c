/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:07:36 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 15:01:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	char_counter(const char *str, int c)
{
	size_t counter;
	
	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}

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