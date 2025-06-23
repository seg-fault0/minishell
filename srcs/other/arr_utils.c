/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:26:10 by wimam             #+#    #+#             */
/*   Updated: 2025/06/23 17:04:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_arr_size(char **arr)
{
	int	size;

	if (!arr)
		return (0);
	size = 0;
	while (arr[size])
		size++;
	return (size);
}

char	**get_2darr_cp(char **arr)
{
	char	**ret;
	int		size;
	int		i;

	size = get_arr_size(arr);
	ret = malloc((size + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	i = -1;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = NULL;
	return (ret);
}

char	**extract_from_arr(char **arr, char *to_extract)
{
	char	**new_arr;
	int		size;
	int		i;
	int		j;

	if (!arr)
		return (NULL);
	size = get_arr_size(arr);
	new_arr = malloc((size + 1) * sizeof(char **));
	if (!new_arr)
		return (NULL);
	i = -1;
	j = 0;
	while (arr[++i])
	{
		if (ft_memcmp(arr[i], to_extract, ft_strlen(to_extract)) != 0)
		{
			new_arr[j] = ft_strdup(arr[i]);
			j++;
		}
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char	**add_to_arr(char **arr, char *to_add)
{
	char	**new_arr;
	int		size;
	int		i;

	if (!arr)
		return (NULL);
	size = get_arr_size(arr);
	new_arr = malloc((size + 1 + 1) * sizeof(char **));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i++] = ft_strdup(to_add);
	new_arr[i] = NULL;
	return (new_arr);
}

void	sort_arr(char **arr)
{
	int		size;
	int		i;
	int		swapped;
	char	*tmp;

	size = get_arr_size(arr);
	if (size < 2)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (diff_strcmp(arr[i], arr[i + 1]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}
