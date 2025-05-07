/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:05:25 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 15:11:23 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
}