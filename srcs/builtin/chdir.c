/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:38 by wimam             #+#    #+#             */
/*   Updated: 2025/06/27 03:33:39 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	chdir_synthax(t_ms *ms)
{
	if (ms->cmd.cmd[ms->cmd.counter][1] == NULL)
		return (TRUE);
	if (ms->cmd.cmd[ms->cmd.counter][2] != NULL)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR), FALSE);
	return (TRUE);
}

static char	**update_env(char **env)
{
	char	**new_env;
	char	**tmp_arr;
	char	*new_wd;
	char	*old_wd;
	char	*tmp_str;

	old_wd = ft_strjoin("OLDPWD=", get_env(env, "PWD"));
	tmp_str = getcwd(NULL, 0);
	new_wd = ft_strjoin("PWD=", tmp_str);
	new_env = extract_from_arr(env, "PWD");
	tmp_arr = extract_from_arr(new_env, "OLDPWD");
	free2(new_env, HEAP);
	new_env = tmp_arr;
	tmp_arr = add_to_arr(new_env, new_wd);
	free2(new_env, HEAP);
	new_env = add_to_arr(tmp_arr, old_wd);
	free2(tmp_arr, HEAP);
	return (free(tmp_str), free(new_wd), free(old_wd), free2(env, HEAP),
		new_env);
}

void	ft_chdir(t_ms *ms)
{
	char	*path;
	int		counter;

	counter = ms->cmd.counter;
	if (chdir_synthax(ms) == FALSE)
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	if (ms->cmd.cmd[counter][1] == NULL)
		path = get_env(ms->env, "HOME");
	else
		path = ms->cmd.cmd[counter][1];
	if (!path)
		return (ms->cmd.cur_exit_code = 1, (void) 0);
	if (chdir(path) == -1)
	{
		ms->cmd.cur_exit_code = 1;
		return (err_msg(ERR_CHDIR_F));
	}
	ms->env = update_env(ms->env);
	ms->cmd.cur_exit_code = 0;
}
