/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:04:42 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 12:22:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void get_paths(t_ms *ms)
{
	char	*path_str;
	char	*tmp;
	int		i;

	i = -1;
	path_str = NULL;
	while (ms->env[++i])
	{
		if (ft_memcmp(ms->env[i], "PATH=", 5) == 0)
		{
			path_str = ms->env[i] + 5;
			break ;
		}
	}
	if (!path_str)
		return ;
	ms->cmd.paths = ft_split(path_str, ':');
	i = -1;
	while (ms->cmd.paths[++i])
	{
		tmp = ms->cmd.paths[i];
		if (tmp[ft_strlen(tmp) - 1] != '/')
		{
			ms->cmd.paths[i] = ft_strjoin(tmp, "/");
			free(tmp);
		}
	}	
}

BOOL	init_struct(t_ms *ms, char **env)
{
	ft_memset(ms, 0, sizeof(t_ms));
	ms->env = env;
	get_paths(ms);
	return (TRUE);
}