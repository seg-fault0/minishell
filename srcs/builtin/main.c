/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/06/23 16:50:38 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_strcmp(cmd, "env") == TRUE)
		print_arr(ms->env);
	else if (ft_strcmp(cmd, "exit") == TRUE)
		built_in_exit(ms);
	else if (ft_strcmp(cmd, "cd") == TRUE)
		ft_chdir(ms);
	else if (ft_strcmp(cmd, "echo") == TRUE)
		ft_echo(ms);
	else if (ft_strcmp(cmd, "pwd") == TRUE)
		ft_pwd(ms);
	else if (ft_strcmp(cmd, "export") == TRUE)
		set_env(ms);
	else if (ft_strcmp(cmd, "unset") == TRUE)
		unset_env(ms);
	if (is_main_process_exe(cmd) == TRUE
		&& ms->cmd.counter == 0 && ms->cmd.max_counter == 1)
		return ;
	ft_exit(ms);
}
