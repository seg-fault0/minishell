/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:01:09 by wimam             #+#    #+#             */
/*   Updated: 2025/05/24 11:01:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_ms *ms)
{
	char	**cmd_args;
	int	i;
	int	j;

	cmd_args = ms->cmd.cmd[ms->cmd.counter];
	i = 0;
	while (cmd_args[++i])
	{
		j = -1;
		while (cmd_args[i][++j])
		{
			if (ft_memcmp(&cmd_args[i][j], "$?", 2) == 0)
			{
				ft_putnbr(ms->cmd.last_exit_code);
				j++;
			}
			else
				write(STDOUT, &cmd_args[i][j], 1);
		}
	}
	printf("\n");
}
