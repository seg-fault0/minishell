/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:55:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/26 00:14:41 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	update_quote_state(char c, char *quote)
{
	if (*quote == 0 && is_quote(c))
		*quote = c;
	else if (*quote == c)
		*quote = 0;
}

static int	skip_redirections(char *cmd, int i)
{
	char	quote;

	quote = 0;
	while (cmd[i])
	{
		update_quote_state(cmd[i], &quote);
		if (!quote && is_redirection(cmd[i]))
		{
			i = skip_redirection(cmd, i);
			while (cmd[i] && !is_space(cmd[i]))
				i++;
			while (is_space(cmd[i]))
				i++;
		}
		else if (!is_space(cmd[i]))
			break ;
		else
			i++;
	}
	return (i);
}

static void	copy_command_content(char *cmd, char *res, int *i, int *j)
{
	char	quote;

	quote = 0;
	while (cmd[*i])
	{
		update_quote_state(cmd[*i], &quote);
		if (!quote && is_redirection(cmd[*i]))
			*i = skip_redirection(cmd, *i);
		else
			res[(*j)++] = cmd[(*i)++];
	}
}

char	*extract_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	i = skip_redirections(cmd, i);
	if (cmd[i])
		copy_command_content(cmd, res, &i, &j);
	res[j] = '\0';
	return (res);
}
