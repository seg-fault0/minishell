/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:07:06 by wimam             #+#    #+#             */
/*   Updated: 2025/05/25 16:44:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exe(t_ms *ms, char *cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0)
		print_env(ms);
	else if (ft_memcmp(cmd, "exit", 4) == 0)
		built_in_exit(ms);
	else if (ft_memcmp(cmd, "cd", 2) == 0)
		ft_chdir(ms);
	else if (ft_memcmp(cmd, "echo", 4) == 0)
		ft_echo(ms);
	else if (ft_memcmp(cmd, "pwd", 3) == 0)
		ft_pwd(ms);
	else if (ft_memcmp(cmd, "export", 6) == 0)
		set_env(ms);
	else if (ft_memcmp(cmd, "unset", 5) == 0)
		unset_env(ms);
	if (is_main_process_exe(cmd) == TRUE && ms->cmd.counter == 0)
		return ;
	ft_exit(ms);
}
