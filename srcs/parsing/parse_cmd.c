/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:37 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/16 10:56:07 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_redirection(char *cmd, int i)
{
	i++;
	while (cmd[i] && is_space(cmd[i]))
		i++;
	while (cmd[i] && !is_space(cmd[i]) && cmd[i] != '<' && cmd[i] != '>')
		i++;
	return (i);
}

static void	copy_cmd(char *cmd, char *res, int *i, int *j)
{
	int	space_allowed;

	space_allowed = 0;
	while (cmd[*i])
	{
		if (cmd[*i] == '<' || cmd[*i] == '>')
		{
			*i = skip_redirection(cmd, *i);
		}
		else if (is_space(cmd[*i]))
		{
			if (space_allowed)
			{
				res[(*j)++] = ' ';
				space_allowed = 0;
			}
			(*i)++;
		}
		else
		{
			res[(*j)++] = cmd[*i];
			space_allowed = 1;
			(*i)++;
		}
	}
}

static char	*extract_cmd(char *cmd)
{
	int		j;
	int		i;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	copy_cmd(cmd, res, &i, &j);
	if (j > 0 && res[j - 1] == ' ')
		j--;
	res[j] = '\0';
	if (j == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

void	parse_cmd(t_ms *ms)
{
	int		i;
	char	*clean;

	i = 0;
	ms->parse.cmd = malloc(sizeof(char **) * (ms->parse.cmd_nbr + 1));
	if (!ms->parse.cmd)
		return ;
	while (i < ms->parse.cmd_nbr)
	{
		clean = extract_cmd(ms->parse.tmp2d[i]);
		if (!clean)
			ms->parse.cmd[i] = NULL;
		else
		{
			ms->parse.cmd[i] = ft_split(clean, ' ');
			free(clean);
		}
		i++;
	}
	ms->parse.cmd[i] = NULL;
}
