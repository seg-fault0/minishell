/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:01:09 by wimam             #+#    #+#             */
/*   Updated: 2025/05/27 11:35:35 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	flag_handler(t_ms *ms, char *str, int *i)
{
	if (ft_memcmp(str, "$?", 2) == 0)
		ft_putnbr(ms->cmd.last_exit_code);
	*i += 1;
}

void	ft_echo(t_ms *ms)
{
	char	**cmd_args;
	int		i;
	int		j;

	cmd_args = ms->cmd.cmd[ms->cmd.counter];
	i = 0;
	while (cmd_args[++i])
	{
		j = -1;
		while (cmd_args[i][++j])
		{
			if (ft_memcmp(&cmd_args[i][j], "$?", 2) == 0)
				flag_handler(ms, &cmd_args[i][j], &j);
			else
				write(STDOUT, &cmd_args[i][j], 1);
		}
		if (cmd_args[i + 1])
			write(STDOUT, " ", 1);
	}
	printf("\n");
	ms->cmd.cur_exit_code = 0;
}
