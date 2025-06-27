/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:04:42 by wimam             #+#    #+#             */
/*   Updated: 2025/06/27 03:46:08 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

BOOL	init_struct(t_ms *ms, char **env)
{
	ft_memset(ms, 0, sizeof(t_ms));
	ms->env = get_2darr_cp(env);
	ms->cwd = get_env(ms->env, "PWD");
	ms->parse.oufiles = NULL;
	ms->parse.infiles = NULL;
	ms->fd.out = NULL;
	ms->parse.tmp2d = NULL;
	ms->parse.infiles = NULL;
	ms->parse.oufiles = NULL;
	return (TRUE);
}
