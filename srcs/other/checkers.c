/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:32 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 19:09:43 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	is_builtin(char	*cmd)
{
	if (ft_memcmp(cmd, "env", 3) == 0
		|| ft_memcmp(cmd, "exit", 4) == 0
		|| ft_memcmp(cmd, "cd", 2) == 0
		|| ft_memcmp(cmd, "echo", 4) == 0
		|| ft_memcmp(cmd, "pwd", 3) == 0
		|| ft_memcmp(cmd, "export", 6) == 0
		|| ft_memcmp(cmd, "unset", 5) == 0)
		return (TRUE);
	return (FALSE);
}

BOOL	is_main_process_exe(char *cmd)
{
	if (ft_memcmp(cmd, "cd", 3) == 0
		|| ft_memcmp(cmd, "exit", 4) == 0
		|| ft_memcmp(cmd, "export", 6) == 0
		|| ft_memcmp(cmd, "unset", 5) == 0)
		return (TRUE);
	return (FALSE);
}
