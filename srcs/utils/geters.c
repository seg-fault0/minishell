/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:33:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 10:45:58 by wimam            ###   ########.fr       */
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
