/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:13:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/15 17:53:49 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	**quote_protect(char *str, int len)
{
	int		i;
	char	quote;
	char	**tmp;

	i = 0;
	quote = 0;
	while (i < len)
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if (!quote && str[i] == '|')
			str[i] = '\0';
		i++;
	}
	tmp = ft_split_len(str, '\0', len);
	return (tmp);
}

int	pipe_counter(const char *str, char delimiter)
{
	int		count;
	char	in_quote;

	count = 0;
	in_quote = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			if (in_quote == 0)
				in_quote = *str;
			else if (in_quote == *str)
				in_quote = 0;
		}
		else if (*str == delimiter && !in_quote)
		{
			count++;
		}
		str++;
	}
	return (count);
}
