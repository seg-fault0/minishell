/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/20 17:31:30 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*extract_unquoted_redirs(char *cmd)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(cmd) + 1);
	if (!res)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '>' && is_outside_quotes(cmd, &cmd[i]))
		{
			res[j++] = '>';
			if (cmd[i + 1] == '>')
				res[j++] = cmd[++i];
			i++;
			while (cmd[i] && is_space(cmd[i]))
				i++;
			while (cmd[i] && !is_space(cmd[i]) && cmd[i] != '>')
				res[j++] = cmd[i++];
			res[j++] = ' ';
		}
		else
			i++;
	}
	res[j] = '\0';
	return (res);
}

static size_t	get_append_flags(char *redirs)
{
	size_t	flags;
	int		count;
	int		i;

	flags = 0;
	count = 0;
	i = 0;
	while (redirs[i])
	{
		if (redirs[i] == '>')
		{
			if (redirs[i + 1] == '>')
			{
				flags |= (1 << count);
				i++;
			}
			count++;
		}
		i++;
	}
	return (flags);
}

void	parse_outfile(t_ms *ms)
{
	int		i;
	char	*redirs;
	char	*clean_redirs;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		if (char_search(ms->parse.tmp2d[i], '>'))
		{
			redirs = extract_unquoted_redirs(ms->parse.tmp2d[i]);
			if (!redirs)
				return ;
			clean_redirs = ft_strjoin(redirs, " ");
			ms->fd.append[i] = get_append_flags(redirs);
			ms->parse.oufiles[i] = ft_split(clean_redirs, ' ');
			int k = 0;
			while (ms->parse.oufiles[i][k])
			{
				printf("  outfile[%d][%d] = %s\n", i, k,
					ms->parse.oufiles[i][k]);
				k++;
			}
			free(redirs);
			free(clean_redirs);
		}
		else
			ms->parse.oufiles[i] = NULL;
	}
	ms->parse.oufiles[i] = NULL;
}
