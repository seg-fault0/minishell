/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 16:45:46 by wimam            ###   ########.fr       */
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
