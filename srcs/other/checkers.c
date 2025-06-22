/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:32 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 19:28:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	is_builtin(char	*cmd)
{
	if (!cmd)
		return (FALSE);
	if (ft_strcmp(cmd, "env") == TRUE
		|| ft_strcmp(cmd, "exit") == TRUE
		|| ft_strcmp(cmd, "cd") == TRUE
		|| ft_strcmp(cmd, "echo") == TRUE
		|| ft_strcmp(cmd, "pwd") == TRUE
		|| ft_strcmp(cmd, "export") == TRUE
		|| ft_strcmp(cmd, "unset") == TRUE)
		return (TRUE);
	return (FALSE);
}

BOOL	is_main_process_exe(char *cmd)
{
	if (!cmd)
		return (FALSE);
	if (ft_strcmp(cmd, "cd") == TRUE
		|| ft_strcmp(cmd, "exit") == TRUE
		|| ft_strcmp(cmd, "export") == TRUE
		|| ft_strcmp(cmd, "unset") == TRUE)
		return (TRUE);
	return (FALSE);
}

BOOL	is_space(int c)
{
	if (c == ' '
		|| c == '\v'
		|| c == '\r'
		|| c == '\t'
		|| c == '\f'
		|| c == '\n')
		return (TRUE);
	return (FALSE);
}

BOOL	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

BOOL	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}
