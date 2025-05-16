/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:12:00 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/16 19:30:11 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_row_len(const char *s, char c, size_t size)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		while (i < size && s[i] == c)
			i++;
		if (i < size && s[i] != c)
		{
			count++;
			while (i < size && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_create_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	if (len == 0)
		return (NULL);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_get_next_word(const char *s, char c,
	size_t *offset, size_t size)
{
	const char	*start;
	size_t		word_len;

	while (*offset < size && s[*offset] == c)
		(*offset)++;
	start = s + *offset;
	word_len = 0;
	while (*offset < size && s[*offset] != c)
	{
		(*offset)++;
		word_len++;
	}
	return (ft_create_word(start, word_len));
}

char	**ft_split_len(const char *s, char c, size_t size)
{
	char	**buffer;
	size_t	i;
	size_t	offset;
	char	*word;

	i = 0;
	offset = 0;
	if (!s)
		return (NULL);
	buffer = malloc((ft_row_len(s, c, size) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (offset < size)
	{
		word = ft_get_next_word(s, c, &offset, size);
		if (!word)
			continue ;
		buffer[i++] = word;
	}
	buffer[i] = NULL;
	return (buffer);
}
