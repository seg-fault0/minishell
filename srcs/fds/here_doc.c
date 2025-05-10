/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:08:30 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 14:23:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc(t_ms *ms)
{
	char	*line;
	char	*delimiter;
	int		pfd[2];

	delimiter = ms->parse.delimiter;
	if (pipe(pfd) == -1)
		return (err_msg(ERR_PIPE_F));
	ft_putstr_fd(HERE_DOC, STDOUT);
	line = get_next_line(STDIN);
	if (!line)
		return (close_pipe(pfd));
	while (line && ft_strcmp(line, delimiter) == FALSE)
	{
		write (pfd[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd(HERE_DOC, STDOUT);
		line = get_next_line(STDIN);
	}
	get_next_line(GNL_FREE);
	close(pfd[1]);
	ms->fds.infd = pfd[0];
}
