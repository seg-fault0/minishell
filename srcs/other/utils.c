/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:07:36 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 18:38:09 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	char_counter(const char *str, int c)
{
	size_t	counter;

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

char	**get_2darr_cp(char **arr)
{
	char	**ret;
	int		size;
	int		i;

	size = 0;
	while (arr[size])
		size++;
	ret = malloc((size + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	i = -1;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = NULL;
	return (ret);
}
