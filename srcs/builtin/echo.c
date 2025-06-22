/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:01:09 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 19:18:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] == 'n')
		i = 2;
	else
		return (FALSE);
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_echo(t_ms *ms)
{
	char	**cmd_args;
	int		i;
	int		newline;

	cmd_args = ms->cmd.cmd[ms->cmd.counter];
	i = 1;
	newline = TRUE;
	while (cmd_args[i] && is_flag(cmd_args[i]) == TRUE)
	{
		newline = FALSE;
		i++;
	}
	while (cmd_args[i])
	{
		write(STDOUT_FILENO, cmd_args[i], ft_strlen(cmd_args[i]));
		if (cmd_args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (newline == TRUE)
		write(STDOUT_FILENO, "\n", 1);
	ms->cmd.cur_exit_code = 0;
}
