/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:04:42 by wimam             #+#    #+#             */
/*   Updated: 2025/06/29 19:47:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_default_env(t_ms *ms)
{
	char	*pwd;
	char	*tmp;
	char	**tmp2;

	if (get_env(ms->env, "PATH") == NULL)
	{
		tmp2 = ms->env;
		ms->env = add_to_arr(tmp2, PTH);
		free2(tmp2, HEAP);
	}
	if (get_env(ms->env, "PWD") == NULL)
	{
		pwd = getcwd(NULL, 0);
		tmp = ft_strjoin("PWD=", pwd);
		tmp2 = ms->env;
		ms->env = add_to_arr(tmp2, tmp);
		free(pwd);
		free(tmp);
		free2(tmp2, HEAP);
	}
}

BOOL	init_struct(t_ms *ms, char **env)
{
	ft_memset(ms, 0, sizeof(t_ms));
	ms->env = get_2darr_cp(env);
	set_default_env(ms);
	ms->cwd = get_env(ms->env, "PWD");
	ms->parse.oufiles = NULL;
	ms->parse.infiles = NULL;
	ms->fd.out = NULL;
	ms->parse.tmp2d = NULL;
	ms->parse.infiles = NULL;
	ms->parse.oufiles = NULL;
	return (TRUE);
}
