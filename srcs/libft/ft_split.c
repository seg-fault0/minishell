/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:08:51 by wimam             #+#    #+#             */
/*   Updated: 2025/06/29 22:11:18 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_row(char const *s, char c)
{
	int		ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			ret++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

static char	*ft_fill(char const *s, char c)
{
	int		len;
	char	*buffer;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s, len);
	buffer[len] = '\0';
	return (buffer);
}

static void	fill_buffer(char **buffer, const char *s, char c, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			buffer[i++] = ft_fill(s, c);
			while (*s && *s != c)
				s++;
		}
		else
			buffer[i++] = ft_strdup("");
	}
	buffer[row] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		row;
	int		len;

	if (!s)
		return (NULL);
	row = ft_row(s, c);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == c)
		row++;
	buffer = malloc((row + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	fill_buffer(buffer, s, c, row);
	return (buffer);
}
