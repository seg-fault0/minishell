/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:37 by wimam             #+#    #+#             */
/*   Updated: 2025/05/24 13:28:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_ms *ms)
{
	int	code;

	code = ms->cmd.cur_exit_code;
	reset_prompt(ms);
	free2(ms->cmd.paths, HEAP);
	free2(ms->env, HEAP);
	rl_clear_history();
	exit(code);
}
