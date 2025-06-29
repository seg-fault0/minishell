/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:13:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/29 22:18:41 by zogrir           ###   ########.fr       */
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

BOOL	is_redirection(char c)
{
	return (c == '<' || c == '>');
}

int	skip_redirection(char *cmd, int i)
{
	if (cmd[i] == '<' && cmd[i + 1] == '<')
		i += 2;
	else if (cmd[i] == '>' && cmd[i + 1] == '>')
		i += 2;
	else
		i++;
	while (cmd[i] && is_space(cmd[i]))
		i++;
	return (i);
}

char	*ft_ft(char	*str)
{
	char	*start;
	char	*filename;
	char	*new;
	int		len;

	filename = extract_first_missing_filename(str);
	if (filename == NULL)
		return (ft_strdup(str));
	start = ft_strstr(str, filename);
	len = start - str + ft_strlen(filename);
	new = malloc(len + 1);
	ft_memcpy(new, str, len);
	new[len] = '\0';
	return (free(filename), new);
}
