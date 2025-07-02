/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/07/02 20:25:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char **env, char *look_for)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(look_for);
	while (env[++i])
	{
		if (ft_strncmp(env[i], look_for, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
	}
	return (NULL);
}

void	env(t_ms *ms)
{
	int	i;

	i = -1;
	while (ms->env[++i])
	{
		if (ft_strchr(ms->env[i], '='))
			printf("%s\n", ms->env[i]);
	}
	ms->cmd.cur_exit_code = 0;
}
