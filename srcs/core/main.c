/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:36:25 by wimam             #+#    #+#             */
/*   Updated: 2025/06/26 15:39:03 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_ms	ms;

	(void) ac;
	(void) av;
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		return (0);
	if (init_struct(&ms, env) == FALSE)
		return (1);
	ft_luncher(&ms);
	ft_exit(&ms);
}
