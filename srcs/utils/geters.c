/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 17:19:33 by wimam            ###   ########.fr       */
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

char	**get_2darr_cp(char **arr)
{
	char	**ret;
	int		size;
	int		i;

	size = 0;
	while (arr[size])
		size++;
	ret = malloc((size + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	i = -1;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = NULL;
	return (ret);
}
