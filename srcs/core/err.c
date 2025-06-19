/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:05:25 by wimam             #+#    #+#             */
/*   Updated: 2025/06/19 20:42:16 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_msg(int msg)
{
	if (msg == ERR_ALLOC_F)
		ft_putstr_fd("ERR : allocation failed\n", 2);
	else if (msg == ERR_PIPE_F)
		ft_putstr_fd("ERR : pipe creation failed\n", 2);
	else if (msg == ERR_FORK_F)
		ft_putstr_fd("ERR : fork failed\n", 2);
	else if (msg == ERR_EXECVE_F)
		ft_putstr_fd("ERR : execve failed\n", 2);
	else if (msg == ERR_DUP2_F)
		ft_putstr_fd("ERR : dup2 failed\n", 2);
	else if (msg == ERR_CHDIR_F)
		ft_putstr_fd("ERR : chdir failed\n", 2);
	else if (msg == ERR_PWD_F)
		ft_putstr_fd("ERR : pwd failed\n", 2);
	else if (msg == ERR_OPEN_F)
		ft_putstr_fd("ERR : open failed\n", 2);
	else if (msg == ERR_THIS_IS_DIR)
		ft_putstr_fd("ERR : This is dir\n", 2);
	else if (msg == ERR_CMD_NF)
		ft_putstr_fd("ERR : command not found\n", 2);
}
