/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:57:35 by wimam             #+#    #+#             */
/*   Updated: 2025/06/23 19:37:50 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_paths(char **env)
{
	char	**paths;
	char	*path_str;
	int		i;

	path_str = NULL;
	paths = NULL;
	i = -1;
	path_str = get_env(env, "PATH");
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

static void	add_path(t_ms *ms)
{
	char	*tmp;
	int		i;
	int		j;

	if (!ms->cmd.paths)
		return ;
	i = -1;
	while (ms->cmd.cmd[++i])
	{
		j = -1;
		while (ms->cmd.paths[++j] && (is_builtin(ms->cmd.cmd[i][0]) == FALSE)
			&& ms->cmd.cmd[i][0] && ms->cmd.cmd[i][0][0])
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
	ms->cmd.max_counter = ms->parse.cmd_nbr;
	ms->cmd.pids = malloc(ms->cmd.max_counter * sizeof(int *));
	ms->cmd.counter = 0;
	ms->cmd.cmd = ms->parse.cmd;
	ms->cmd.paths = get_paths(ms->env);
	add_path(ms);
}
