/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:45:53 by wimam             #+#    #+#             */
/*   Updated: 2025/06/21 07:47:12 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	here_doc(char *delimiter)
{
	char	*line;
	int		pfd[2];

	if (delimiter[0] == '\'' || delimiter[0] == '"')
		ft_delimiter_extract(delimiter);
	if (pipe(pfd) == -1)
		return (err_msg(ERR_PIPE_F), -1);
	ft_putstr_fd(HERE_DOC, STDOUT);
	line = heredoc_expand(get_next_line(STDIN));
	while (line && (ft_memcmp(line, delimiter, ft_strlen(delimiter)) != 0))
	{
		write(pfd[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd(HERE_DOC, STDOUT);
		line = heredoc_expand(get_next_line(STDIN));
	}
	if (line)
		free(line);
	get_next_line(GNL_FREE);
	return (close(pfd[1]), pfd[0]);
}
