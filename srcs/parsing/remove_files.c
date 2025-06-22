/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:45:01 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 10:40:54 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sep(char c)
{
	return (c == ' ' || c == '<' || c == '>' || c == '\0');
}

char	*get_next_filename(char *s, int *i)
{
	int		j;
	char	*filename;

	j = 0;
	filename = malloc(ft_strlen(s) + 1);
	while (s[*i] == ' ')
		(*i)++;
	while (!is_sep(s[*i]) && s[*i] && j < 255)
		filename[j++] = s[(*i)++];
	filename[j] = '\0';
	return (filename);
}

static char	*get_quoted_filename(char *s, int *i)
{
	char	quote;
	int		j;
	char	*filename;

	quote = s[(*i)++];
	filename = malloc(ft_strlen(s) + 2);
	if (!filename)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != quote)
		filename[j++] = s[(*i)++];
	filename[j] = '\0';
	if (s[*i] == quote)
		(*i)++;
	return (filename);
}

char	*extract_first_missing_filename(char *s)
{
	int		i;
	char	*filename;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<')
		{
			i++;
			if (s[i] == '<')
				break ;
			while (s[i] == ' ')
				i++;
			if (s[i] == '\'' || s[i] == '"')
				filename = get_quoted_filename(s, &i);
			else
				filename = get_next_filename(s, &i);
			if (access(filename, R_OK) != 0)
				return (filename);
			free(filename);
		}
		else
			i++;
	}
	return (NULL);
}
