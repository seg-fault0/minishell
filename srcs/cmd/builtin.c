/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 10:17:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->env[i])
		printf("%s\n", ms->env[i++]);
}

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0)
		ft_env(ms);
}
