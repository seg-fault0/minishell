/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:04:42 by wimam             #+#    #+#             */
/*   Updated: 2025/05/17 11:33:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

BOOL	init_struct(t_ms *ms, char **env)
{
	ft_memset(ms, 0, sizeof(t_ms));
	ms->env = get_2darr_cp(env);
	ms->parse.oufiles = NULL;
	ms->parse.infiles = NULL;
	return (TRUE);
}
