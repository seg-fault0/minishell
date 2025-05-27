/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:45:53 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 10:07:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doc(char *delimiter)
{
	char	*line;
	int		pfd[2];

	if (pipe(pfd) == -1)
		return (err_msg(ERR_PIPE_F), -1);
	ft_putstr_fd(HERE_DOC, STDOUT);
	line = get_next_line(STDIN);
	while (line && (ft_memcmp(line, delimiter, ft_strlen(delimiter)) != 0))
	{
		write(pfd[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd(HERE_DOC, STDOUT);
		line = get_next_line(STDIN);
	}
	if (line)
		free(line);
	get_next_line(GNL_FREE);
	return (close(pfd[1]), pfd[0]);
}
