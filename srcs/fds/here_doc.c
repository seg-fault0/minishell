/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:45:53 by wimam             #+#    #+#             */
/*   Updated: 2025/06/24 17:52:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_chiled(t_ms *ms, char *delimiter, int *pfd)
{
	char	*line;

	heredoc_signals();
	close(pfd[0]);
	line = heredoc_expand(ms, readline(HERE_DOC));
	while (line && (ft_strcmp(line, delimiter) == FALSE))
	{	
		write(pfd[1], line, ft_strlen(line));
		write(pfd[1], "\n", 1);
		free(line);
		line = heredoc_expand(ms, readline(HERE_DOC));
	}
	if (line)
		free(line);
	close(pfd[1]);
	exit(0);
}

int	here_doc(t_ms *ms, char *delimiter)
{
	int	pfd[2];
	int	pid;
	int	code;

	if (delimiter[0] == '\'' || delimiter[0] == '"')
		ft_delimiter_extract(delimiter);
	if (pipe(pfd) == -1)
		return (err_msg(ERR_PIPE_F), -1);
	pid = fork();
	if (pid == -1)
		return (err_msg(ERR_FORK_F), -1);
	if (pid == 0)
		heredoc_chiled(ms, delimiter, pfd);
	else
	{
		close(pfd[1]);
		wait(&code);
		ms->cmd.cur_exit_code = WEXITSTATUS(code);
	}
	if (ms->cmd.cur_exit_code == 130)
		return (130);
	return (pfd[0]);
}
