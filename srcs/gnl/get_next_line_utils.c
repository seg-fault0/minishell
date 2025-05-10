/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:06:44 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 14:07:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_init(char *str)
{
	char	*buffer;

	if (!str)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
		return (buffer);
	}
	return (str);
}

int	ft_new_line_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strljoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	int		len;
	char	*buffer;

	len = ft_strlen(s1) + size;
	buffer = malloc(len + 1);
	if (!buffer || !s2)
		return (NULL);
	if (!s1)
		s1 = ft_init(NULL);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	j = 0;
	while (s2[j] != '\0' && j < size)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1);
	return (buffer);
}
