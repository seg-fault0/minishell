/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:46:58 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 15:06:45 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int			len;
	char		*buffer;
	int			i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*buffer;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (*s1)
	{
		buffer[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		buffer[i++] = *s2;
		s2++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}