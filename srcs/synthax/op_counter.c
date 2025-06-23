/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:45:25 by wimam             #+#    #+#             */
/*   Updated: 2025/06/23 16:03:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	counter(const char *str, char op)
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
		else if (*str == op && !in_quote)
		{
			count++;
			if (*(str + 1) == op)
				str++;
		}
		str++;
	}
	return (count);
}

BOOL	op_counter(char *input)
{
	int		max;
	int		i;
	char	**tmp;

	max = counter(input, '|');
	if (max > MAX_CMD)
		return (ft_putstr_fd("too much commands\n", STDERR), TRUE);
	tmp = split_cmd(input);
	i = 0;
	while (i < max + 1)
	{
		if (counter(tmp[i], '>') > MAX_FD
			|| counter(tmp[i], '<') > MAX_FD)
			return (free2(tmp, HEAP),
				ft_putstr_fd("too much fds\n", STDERR), TRUE);
		i++;
	}
	free2(tmp, HEAP);
	return (FALSE);
}
