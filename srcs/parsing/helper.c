/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:13:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/20 15:54:35 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	**split_cmd(const char *input)
{
	int		i;
	char	quote;
	char	**tmp;
	char	*input_cpy;
	int		input_len;

	input_cpy = ft_strdup(input);
	if (!input_cpy)
		return (NULL);
	input_len = ft_strlen(input);
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
BOOL is_outside_quotes(char *cmd, char *c_ptr)
{
	int i = 0;
	int in_single = 0;
	int in_double = 0;

	while (&cmd[i] < c_ptr)
	{
		if (cmd[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (cmd[i] == '\"' && !in_single)
			in_double = !in_double;
		i++;
	}
	return (!in_single && !in_double);
}
BOOL	is_redirection(char c)
{
	return (c == '<' || c == '>');
}