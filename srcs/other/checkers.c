/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:32 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 16:24:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	is_builtin(char	*str)
{
	if (ft_memcmp(str, "env", 3) == 0
		|| ft_memcmp(str, "exit", 4) == 0
		|| ft_memcmp(str, "cd", 2) == 0
		|| ft_memcmp(str, "echo", 4) == 0
		|| ft_memcmp(str, "pwd", 3) == 0)
		return (TRUE);
	return (FALSE);
}
