/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:49 by wimam             #+#    #+#             */
/*   Updated: 2025/05/11 11:58:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free2(char **arr, int c)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	if (c == HEAP)
		free(arr);
}

void	free3(char ***arr, int c)
{
	int	i;
	int	j;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			free(arr[i][j]);
		free(arr[i]);
	}
	if (c == HEAP)
		free(arr);
}
