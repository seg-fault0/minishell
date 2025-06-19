/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:55:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/19 19:04:16 by wimam            ###   ########.fr       */
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

static int	skip_redirection_with_quotes(char *cmd, int i)
{
	char	quote;

	quote = 0;
	while (cmd[i] && (quote || !is_space(cmd[i])))
	{
		update_quote_state(cmd[i], &quote);
		i++;
	}
	return (i);
}

char	*extract_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*res;
	char	quote;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	quote = 0;
	while (cmd[i])
	{
		update_quote_state(cmd[i], &quote);
		if (!quote && is_redirection(cmd[i]))
		{
			i = skip_redirection(cmd, i);
			i = skip_redirection_with_quotes(cmd, i);
			while (is_space(cmd[i]))
				i++;
		}
		else
			res[j++] = cmd[i++];
	}
	res[j] = '\0';
	return (res);
}
