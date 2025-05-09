/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:06:47 by wimam             #+#    #+#             */
/*   Updated: 2025/05/09 14:13:09 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	char_search(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	char_counter(const char *str, int c)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
