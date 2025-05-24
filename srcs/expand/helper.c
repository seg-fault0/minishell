/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:50 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/24 10:06:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	is_in_single_quotes(const char *str, int pos)
{
	int		i;
	int		squote;
	int		dquote;

	squote = 0;
	dquote = 0;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && dquote == 0)
			squote = !squote;
		else if (str[i] == '\"' && squote == 0)
			dquote = !dquote;
		i++;
	}
	return (squote);
}
