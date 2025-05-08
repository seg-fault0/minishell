/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:57:35 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 16:14:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_path(t_ms *ms)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (ms->cmd.cmd[++i])
	{
		j = -1;
		while (ms->cmd.paths[++j] && (is_builtin(ms->cmd.cmd[i][0]) == FALSE))
		{
			tmp = ft_strjoin(ms->cmd.paths[j], ms->cmd.cmd[i][0]);
			if (access(tmp, X_OK) == 0)
			{
				free(ms->parse.cmd[i][0]);
				ms->cmd.cmd[i][0] = tmp;
				break ;
			}
			free(tmp);
		}
	}
}

void	init_cmd(t_ms *ms)
{
	ms->cmd.max_counter = char_counter(ms->input, '|') + 1;
	ms->cmd.counter = 0;
	ms->cmd.cmd = ms->parse.cmd;
	add_path(ms);
}
