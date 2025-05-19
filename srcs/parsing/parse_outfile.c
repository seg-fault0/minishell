/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/19 17:00:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*get_outfiles_str(char *cmd)
{
	char	*res;
	int		i;

	while (*cmd != '>')
		cmd++;
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!res)
		return (free(res), NULL);
	i = 0;
	while (*cmd)
	{
		if (is_space(*cmd) == FALSE)
			res[i++] = *cmd;
		cmd++;
	}
	res[i] = '\0';
	return (res);
}

static int	append_scanner(char	*files_str)
{
	int	file;
	int	ret;
	int	i;

	file = 0;
	ret = 0;
	i = 0;
	while (files_str[i])
	{
		if (files_str[i] == '>')
		{
			if (files_str[i + 1] == '>')
			{
				ret |= (1 << file);
				i++;
			}
			file++;
		}
		i++;
	}
	return (ret);
}

void	parse_outfile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		cmd = ms->parse.tmp2d[i];
		if (char_search(cmd, '>'))
		{
			redirect = get_outfiles_str(cmd);
			if (!redirect)
				return ;
			ms->fd.append[i] = append_scanner(redirect);
			ms->parse.oufiles[i] = ft_split(redirect, '>');
			free(redirect);
		}
		else
			ms->parse.oufiles[i] = NULL;
	}
	ms->parse.oufiles[i] = NULL;
}
