/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:55 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 18:33:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	env_synthax(char *str)
{
	if (str[0] == '\0' || str[0] == '='|| is_digit(str[0]))
		return (TRUE);
	return (FALSE);
}

void	set_env(t_ms *ms)
{
	char	**tmp_arr;
	int		counter;
	int		i;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		if (env_synthax(ms->cmd.cmd[counter][i]) == TRUE)
		{
			ft_putstr_fd("bash: export: not a valid identifier\n", STDERR);
			ms->cmd.cur_exit_code = 1;
		}
		else if (ms->cmd.counter == 0)
		{
			tmp_arr = ms->env;
			ms->env = add_to_arr(tmp_arr, ms->cmd.cmd[counter][i]);
			free2(tmp_arr, HEAP);
		}
	}
}
