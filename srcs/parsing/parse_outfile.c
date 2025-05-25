/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/25 22:31:45 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	*get_outfiles_str(char *cmd)
{
	char	*outfiles;
	int		i;
	int		j;

	outfiles = malloc(ft_strlen(cmd) + 1);
	if (!outfiles)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>')
		{
			outfiles[j++] = '>';
			i++;
			while (is_space(cmd[i]))
				i++;
			while (cmd[i] && !is_space(cmd[i])
				&& cmd[i] != '<' && cmd[i] != '>')
				outfiles[j++] = cmd[i++];
		}
		else
			i++;
	}
	return (outfiles[j] = '\0', outfiles);
}

static size_t	append_scanner(char	*files_str)
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
