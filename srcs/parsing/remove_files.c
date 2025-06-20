/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:45:01 by wimam             #+#    #+#             */
/*   Updated: 2025/06/20 09:52:07 by wimam            ###   ########.fr       */
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
