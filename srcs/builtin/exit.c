/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:44:38 by wimam             #+#    #+#             */
/*   Updated: 2025/06/30 00:01:57 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	is_there_char(char *str)
{
	if (!str)
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (is_digit(*str) == FALSE)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

void	built_in_exit(t_ms *ms)
{
	if (is_there_char(ms->cmd.cmd[ms->cmd.counter][1]) == TRUE)
	{
		ft_putstr_fd("numeric argument required\n", STDERR);
		ms->cmd.cur_exit_code = 2;
	}
	else if (ms->cmd.cmd[ms->cmd.counter][2] != NULL)
	{
		ft_putstr_fd("too many arguments\n", STDERR);
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	}
	else if (ms->cmd.cmd[ms->cmd.counter][1])
	{
		ms->cmd.cur_exit_code = ft_atoi(ms->cmd.cmd[ms->cmd.counter][1]);
		if (outrange_long(ms->cmd.cmd[ms->cmd.counter][1]) == TRUE)
		{
			ft_putstr_fd("numeric argument required\n", STDERR);
			ms->cmd.cur_exit_code = 2;
		}
	}
	else
		ms->cmd.cur_exit_code = ms->cmd.last_exit_code;
	printf("exit\n");
	ft_exit(ms);
}
