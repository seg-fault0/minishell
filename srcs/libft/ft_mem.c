/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:10:31 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 10:04:17 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmpdst;
	char	*tmpsrc;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst == src)
		return (dst);
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*buffer;

	i = 0;
	buffer = (char *) b;
	while (i < len)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;
	size_t				i;

	buffer1 = (const unsigned char *) s1;
	buffer2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (buffer1[i] != buffer2[i])
			return (buffer1[i] - buffer2[i]);
		i++;
	}
	return (0);
}
