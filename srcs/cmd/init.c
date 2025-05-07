/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:57:35 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 14:16:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void add_path(t_ms *ms)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (ms->parse.cmd[++i])
	{
		j = -1;
		while(ms->cmd.paths[++j])
		{
			tmp = ft_strjoin(ms->cmd.paths[j], ms->parse.cmd[i][0]);
			if (access(tmp, X_OK) == 0)
			{
				free(ms->parse.cmd[i][0]);
				ms->parse.cmd[i][0] = tmp;
				break ;
			}
			free(tmp);
		}
	}
}

void	init_cmd(t_ms *ms)
{
	add_path(ms);
}