/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:12:00 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/15 12:12:43 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static int	ft_row_len(const char *s, char c, size_t size)
{
	size_t	i = 0;
	int		count = 0;

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

static char	*ft_fill_len(const char *s, char c, size_t *word_len, size_t size, size_t *offset)
{
	const char	*start;
	char		*word;

	while (*offset < size && s[*offset] == c)
		(*offset)++;
	start = s + *offset;
	*word_len = 0;

	while (*offset < size && s[*offset] != c)
	{
		(*offset)++;
		(*word_len)++;
	}

	word = malloc(*word_len + 1);
	if (!word)
		return (NULL);
	memcpy(word, start, *word_len);
	word[*word_len] = '\0';
	return (word);
}

char	**ft_split_len(const char *s, char c, size_t size)
{
	char	**buffer;
	size_t	i = 0;
	size_t	offset = 0;
	size_t	word_len;
	char	*word;

	if (!s)
		return (NULL);
	buffer = malloc((ft_row_len(s, c, size) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (offset < size)
	{
		word = ft_fill_len(s, c, &word_len, size, &offset);
		if (word_len == 0)
		{
			free(word);
			continue;
		}
		if (!word)
			break;
		buffer[i++] = word;
	}
	buffer[i] = NULL;
	return (buffer);
}