/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 07:44:44 by wimam             #+#    #+#             */
/*   Updated: 2025/06/24 16:32:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_expand(t_ms *ms, char *line)
{
	char	*expanded;

	if (!line || !ft_strchr(line, '$'))
		return (line);
	expanded = expand_line_heredoc(ms, line);
	free(line);
	return (expanded);
}

void	ft_delimiter_extract(char *delimiter)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
		{
			quote = delimiter[i++];
			while (delimiter[i] && delimiter[i] != quote)
				delimiter[j++] = delimiter[i++];
			if (delimiter[i] == quote)
				i++;
		}
		else
			delimiter[j++] = delimiter[i++];
	}
	delimiter[j] = '\0';
}
