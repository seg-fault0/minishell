/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:49 by wimam             #+#    #+#             */
/*   Updated: 2025/05/16 11:48:53 by zogrir           ###   ########.fr       */
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

void	free3size(char ***arg, int size)
{
	int i;
	int j;

	i = 0;
	if (!arg)
	return ;
	while (i < size)
	{
		if (arg[i])
		{
			j = 0;
			while (arg[i][j])
			{
				free(arg[i][j]);
				j++;
			}
			free(arg[i]);
		}
		i++;
	}
	free(arg);
}
