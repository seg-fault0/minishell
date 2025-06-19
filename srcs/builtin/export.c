/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:55 by wimam             #+#    #+#             */
/*   Updated: 2025/06/19 17:05:56 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	env_synthax(char *str)
{
	int	i;

	if (str[0] == '\0' || str[0] == '=')
		return (TRUE);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (is_digit(str[i]) || str[i] == '-')
			return (TRUE);
		i++;
	}	
	return (FALSE);
}

void	env_var_checker(t_ms *ms, char *str)
{
	char	*tmp_envar;
	char	**tmp_arr;
	int		len;
	
	tmp_envar = ft_strdup(str);
	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	tmp_envar[len] = '\0';
	if (get_env(ms->env, tmp_envar) == NULL)
	{
		ft_putstr_fd("minishell: export: not a valid identifier\n", STDERR);
		return (free(tmp_envar));
	}
	else
	{
		tmp_arr = ms->env;
		ms->env = extract_from_arr(tmp_arr, tmp_envar);
		free2(tmp_arr, HEAP);
		free(tmp_envar);
	}
}

void	set_env(t_ms *ms)
{
	char	**tmp_arr;
	int		counter;
	int		i;

	counter = ms->cmd.counter;
	i = 0;
	while (ms->cmd.cmd[counter][++i])
	{
		if (env_synthax(ms->cmd.cmd[counter][i]) == TRUE)
			ms->cmd.cur_exit_code = 1;
		else if (ft_strstr(ms->cmd.cmd[counter][i], "="))
		{
			tmp_arr = ms->env;
			ms->env = add_to_arr(tmp_arr, ms->cmd.cmd[counter][i]);
			free2(tmp_arr, HEAP);
		}
	}
}
