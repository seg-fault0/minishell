/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:59:17 by wimam             #+#    #+#             */
/*   Updated: 2025/06/22 18:28:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	ft_atoi(const char *str)
{
	int					signe;
	long				a;
	int					i;

	a = 0;
	i = 0;
	signe = 1;
	if (!str)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (LONG_MAX);
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i++] - '0') * signe;
		if (a > INT_MAX || a < INT_MIN)
			return (LONG_MAX);
	}
	if (str[i])
		return (LONG_MAX);
	return (a);
}
