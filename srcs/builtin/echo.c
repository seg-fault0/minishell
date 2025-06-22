/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:01:09 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 15:29:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_ms *ms)
{
	char	**cmd_args;
	int		i;

	cmd_args = ms->cmd.cmd[ms->cmd.counter];
	i = 0;
	while (cmd_args[++i])
	{
		while (ft_memcmp(cmd_args[i], "-n", 3) == 0)
			i++;
		write(STDOUT, cmd_args[i], ft_strlen(cmd_args[i]));
		if (cmd_args[i + 1])
			write(STDOUT, " ", 1);
	}
	if (!cmd_args[1] || ft_memcmp(cmd_args[1], "-n", 3) != 0)
		printf("\n");
	ms->cmd.cur_exit_code = 0;
}
