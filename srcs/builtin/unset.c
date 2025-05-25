/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:45:31 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 16:45:50 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(t_ms *ms)
{
	char	**tmp_arr;
	int		counter;
	int		i;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		tmp_arr = ms->env;
		ms->env = extract_from_arr(tmp_arr, ms->cmd.cmd[counter][i]);
		free2(tmp_arr, HEAP);
	}
}
