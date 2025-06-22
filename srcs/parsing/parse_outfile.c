/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:56:52 by zogrir            #+#    #+#             */
/*   Updated: 2025/06/22 10:40:42 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	handle_filename(char *cmd, int *i, char *outfiles, int *j)
{
	char	quote;

	while (cmd[*i] && !is_space(cmd[*i]) && cmd[*i] != '<' && cmd[*i] != '>')
	{
		if (cmd[*i] == '\'' || cmd[*i] == '"')
		{
			quote = cmd[(*i)++];
			if (cmd[*i] == quote)
			{
				outfiles[(*j)++] = ' ';
				(*i)++; // skip closing quote
				continue ;
			}
			while (cmd[*i] && cmd[*i] != quote)
				outfiles[(*j)++] = cmd[(*i)++];
			if (cmd[*i] == quote)
				(*i)++;
		}
		else
		{
			outfiles[(*j)++] = cmd[(*i)++];
		}
	}
}

static char	*get_outfiles_str(char *cmd)
{
	char	*outfiles;
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	outfiles = malloc(ft_strlen(cmd) + 1);
	if (!outfiles)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
		{
			quote = cmd[i++];
			while (cmd[i] && cmd[i] != quote)
				i++;
			if (cmd[i] == quote)
				i++;
		}
		else if (cmd[i] == '>')
		{
			outfiles[j++] = '>';
			i++;
			while (is_space(cmd[i]))
				i++;
			handle_filename(cmd, &i, outfiles, &j);
		}
		else
			i++;
	}
	outfiles[j] = '\0';
	return (outfiles);
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

void	parse_outfile(t_ms *ms)
{
	int		i;
	char	*cmd;
	char	*redirect;

	i = -1;
	while (++i < ms->parse.cmd_nbr)
	{
		cmd = ft_ft(ms->parse.tmp2d[i]);
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
		free(cmd);
	}
	ms->parse.oufiles[i] = NULL;
}
