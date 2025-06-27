/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:45:31 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 18:52:03 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(t_ms *ms)
{
	char	**tmp_arr;
	char	*to_extract;
	int		counter;
	int		i;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		to_extract = ft_strjoin(ms->cmd.cmd[counter][i], "=");
		tmp_arr = ms->env;
		ms->env = extract_from_arr(tmp_arr, to_extract);
		free2(tmp_arr, HEAP);
		free(to_extract);
	}
	ms->cmd.cur_exit_code = 0;
}
