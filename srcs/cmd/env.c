/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/24 10:08:52 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_ms *ms)
{
	int	i;

	i = 0;
	if (!ms->env)
		return ;
	while (ms->env[i])
		printf("%s\n", ms->env[i++]);
}

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

char	*get_env_v2(char **env, char *look_for)
{
	int		i;
	size_t	len;

	len = ft_strlen(look_for);
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], look_for, len) && env[i][len] == '=')
			return (env[i] + len + 1);
	}
	return (NULL);
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
		tmp_arr = ms->env;
		ms->env = add_to_arr(tmp_arr, ms->cmd.cmd[counter][i]);
		free2(tmp_arr, HEAP);
	}
}

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
