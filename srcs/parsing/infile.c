/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:29:28 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/10 09:34:37 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	get_infile_name(t_ms *ms)
{
	char	*start;
	int		file_len;

	start = ft_strstr(ms->input, "<");
	if (*(++start) == '\0')
		return (FALSE);
	start += skip_space(start);
	if (!*start)
		return (FALSE);
	file_len = 0;
	while (start[file_len] && !is_space(start[file_len]))
		file_len++;
	ms->parse.instr = malloc(file_len + 1);
	if (!ms->parse.instr)
		return (FALSE);
	ft_memcpy(ms->parse.instr, start, file_len);
	ms->parse.instr[file_len] = '\0';
	return (TRUE);
}

char	*remove_infile(char	*old)
{
	char	*start;
	char	*new;
	int		len;

	start = ft_strstr(old, "<");
	len = start - old;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, old, len);
	new[len] = '\0';
	return (new);
}

char	*remove_infile_redirection(char *old)
{
	char	*start;
	char	*new;

	start = old + 1;
	start += skip_space(start);
	while (*start && !is_space(*start))
		start++;
	start += skip_space(start);
	if (!*start)
		return (NULL);
	new = ft_strdup(start);
	return (new);
}

void	parse_infile(t_ms *ms)
{
	char	*old_input;
	char	*tmp;

	if (get_infile_name(ms) == FALSE)
		return ;
	old_input = ms->input;
	tmp = old_input;
	while (is_space(*tmp))
		tmp++;
	if (*tmp == '<')
		ms->input = remove_infile_redirection(tmp);
	else
		ms->input = remove_infile(tmp);
	if (!ms->input)
		return (ms->input = old_input, (void) 0);
	free(old_input);
}
