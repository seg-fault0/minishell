/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:06:22 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/18 14:27:59 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	is_valid_alpha(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

static int	ft_chcker(char *s, int current)
{
	current++;
	while (s[current])
	{
		if (is_valid_alpha(s[current]))
			return (1);
		current++;
	}
	return (0);
}

int	expand_checker(char *content)
{
	int	is_single_qote;
	int	is_double_qote;
	int	i;

	is_single_qote = 0;
	is_double_qote = 0;
	i = -1;
	while (content[++i])
	{
		if (content[i] == '\'' && !is_double_qote)
			is_single_qote = !is_single_qote;
		else if (content[i] == '"' && !is_single_qote)
			is_double_qote = !is_double_qote;
		else if (content[i] == '$' && !is_single_qote)
			return (ft_chcker(content, i), 1);
	}
	return (0);
}
