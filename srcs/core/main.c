/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:36:25 by wimam             #+#    #+#             */
/*   Updated: 2025/05/24 13:24:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_ms	ms;

	(void) ac;
	(void) av;
	if (init_struct(&ms, env) == FALSE)
		return (1);
	ft_luncher(&ms);
	ft_exit(&ms);
}
