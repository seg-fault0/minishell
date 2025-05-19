/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:13:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/19 11:22:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	**split_cmd(t_ms *ms)
{
	int		i;
	char	quote;
	char	**tmp;
	char	*input_cpy;
	int		input_len;

	input_cpy = ft_strdup(ms->input);
	if (!input_cpy)
		return (NULL);
	input_len = ft_strlen(ms->input);
	quote = 0;
	i = 0;
	while (i < input_len)
	{
		if (!quote && (input_cpy[i] == '\'' || input_cpy[i] == '"'))
			quote = input_cpy[i];
		else if (quote && input_cpy[i] == quote)
			quote = 0;
		else if (!quote && input_cpy[i] == '|')
			input_cpy[i] = '\0';
		i++;
	}
	tmp = ft_split_len(input_cpy, '\0', input_len);
	return (free(input_cpy), tmp);
}

int	cmd_counter(const char *str)
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
		else if (*str == '|' && !in_quote)
			count++;
		str++;
	}
	return (count + 1);
}
