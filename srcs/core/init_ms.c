/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:04:42 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 10:45:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_paths(char **env)
{
	char	**paths;
	char	*path_str;
	int		i;

	path_str = NULL;
	paths = NULL;
	i = -1;
	path_str = get_env(env, "PATH=");
	if (!path_str)
		return (NULL);
	paths = ft_split(path_str, ':');
	i = -1;
	while (paths[++i])
	{
		path_str = paths[i];
		if (path_str[ft_strlen(path_str) - 1] != '/')
		{
			paths[i] = ft_strjoin(path_str, "/");
			free(path_str);
		}
	}
	return (paths);
}

BOOL	init_struct(t_ms *ms, char **env)
{
	ft_memset(ms, 0, sizeof(t_ms));
	ms->env = env;
	ms->cmd.paths = get_paths(env);
	return (TRUE);
}
