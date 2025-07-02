/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:55 by wimam             #+#    #+#             */
/*   Updated: 2025/07/02 15:39:25 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_ms *ms)
{
	char	**tmp;
	int		i;
	int		max;

	max = get_arr_size(ms->env);
	tmp = get_2darr_cp(ms->env);
	sort_arr(tmp);
	i = 0;
	while (i < max)
		printf("declare -x %s\n", tmp[i++]);
	free2(tmp, HEAP);
}

static BOOL	env_synthax(char *str)
{
	int	i;

	if (str[0] == '\0' || str[0] == '=' || is_digit(str[0]))
	{
		ft_putstr_fd("export: not a valid identifier\n", STDERR);
		return (TRUE);
	}
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '-')
		{
			ft_putstr_fd("export: not a valid identifier\n", STDERR);
			return (TRUE);
		}
		i++;
	}	
	return (FALSE);
}

void	add_varg(t_ms *ms, char *var_name, int i)
{
	char	*tmp1;
	char	*tmp2;
	int		counter;

	counter = ms->cmd.counter;
	tmp1 = ft_strjoin(var_name, "=");
	tmp2 = ft_strjoin(tmp1, get_env(ms->env, var_name));
	free(tmp1);
	tmp1 = ms->cmd.cmd[counter][i];
	ms->cmd.cmd[counter][i] = ft_strjoin(tmp2, tmp1 + ft_strlen(var_name) + 2);
	free(tmp1);
	free(tmp2);
}

BOOL	env_var_checker(t_ms *ms, char *str, int i)
{
	char	*tmp_envar;
	char	**tmp_arr;
	int		len;

	tmp_envar = ft_strdup(str);
	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	tmp_envar[len] = '\0';
	if (tmp_envar[len - 1] == '+')
	{
		tmp_envar[--len] = '\0';
		add_varg(ms, tmp_envar, i);
		free(tmp_envar);
		return (FALSE);
	}
	if (get_env(ms->env, tmp_envar) == NULL)
		return (free(tmp_envar), TRUE);
	tmp_arr = ms->env;
	ms->env = extract_from_arr(tmp_arr, tmp_envar);
	free2(tmp_arr, HEAP);
	free(tmp_envar);
	return (TRUE);
}

static void	add_env_if_needed(t_ms *ms, char *arg)
{
	char	**tmp_arr;

	tmp_arr = ms->env;
	ms->env = add_to_arr(tmp_arr, arg);
	free2(tmp_arr, HEAP);
}

static void	handle_env_argument(t_ms *ms, char *arg, int i, int *code)
{
	BOOL	should_add;

	if (env_synthax(arg) == TRUE)
	{
		*code = 1;
		return ;
	}
	if (ft_strstr(arg, "="))
	{
		should_add = env_var_checker(ms, arg, i);
		if (should_add)
			add_env_if_needed(ms, arg);
	}
	else
	{
		should_add = env_var_checker(ms, arg, i);
		if (should_add)
			add_env_if_needed(ms, arg);
	}
}

void	set_env(t_ms *ms)
{
	int	counter;
	int	i;
	int	code;

	counter = ms->cmd.counter;
	code = 0;
	i = 0;
	if (!ms->cmd.cmd[counter][i + 1])
	{
		print_export(ms);
		return ;
	}
	while (ms->cmd.cmd[counter][++i])
		handle_env_argument(ms, ms->cmd.cmd[counter][i], i, &code);
	ms->cmd.cur_exit_code = code;
}
