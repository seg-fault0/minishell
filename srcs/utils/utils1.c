/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:07:36 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 14:21:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	char_counter(const char *str, int c)
{
	size_t counter;
	
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