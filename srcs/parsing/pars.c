/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 13:46:35 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(t_ms *ms)
{
	char	**tmp_cmd;
	int		i;
	
	tmp_cmd = ft_split(ms->input, '|');
	i = 0;
	while (tmp_cmd[i++]);
	ms->cmd.cmd = malloc((i + 1) * sizeof(char **));
	if (!ms->cmd.cmd)
		return (free2(tmp_cmd, HEAP));
	i = -1;
	while (tmp_cmd[++i])
		ms->cmd.cmd[i] = ft_split(tmp_cmd[i], ' ');
	ms->cmd.cmd[i] = NULL;
	free2(tmp_cmd, HEAP);
}