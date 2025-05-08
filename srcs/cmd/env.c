/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 19:16:42 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char **env, char *look_for)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_memcmp(env[i], look_for, 5) == 0)
			return (env[i] + ft_strlen(look_for));
	}
	return (NULL);
}

void	set_env(t_ms *ms)
{
	int		counter;
	int		i;
	int		j;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		j = 0;
		while (ms->env[j])
			j++;
		ms->env[j++] = ft_strdup(ms->cmd.cmd[counter][i]);
		ms->env[j] = NULL;
	}
}

void	unset_env(t_ms *ms)
{
	int		counter;
	int		i;
	int		j;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		j = -1;
		while (ms->env[++j])
		{
			if (ft_memcmp(ms->env[j], ms->cmd.cmd[counter][i], 4) == 0)
			{
				free(ms->env[j]);
				while (ms->env[j])
				{
					ms->env[j] = ms->env[j + 1];
					j++;
				}
			}
			if (!ms->env[j])
				break ;
		}
	}
}
