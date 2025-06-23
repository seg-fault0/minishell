/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:07:43 by wimam             #+#    #+#             */
/*   Updated: 2025/06/23 16:49:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		printf("%s\n", arr[i++]);
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
