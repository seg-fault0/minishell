/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:59:42 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 09:55:57 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	get_file_name(t_ms *ms)
{
	char	*start;
	int		file_len;

	start = ft_strstr(ms->input, ">");
	if (*(++start) == '\0')
		return (FALSE);
	else if (*start == '>')
	{
		ms->fds.append_flag = TRUE;
		start++;
	}
	start += skip_space(start);
	if (!*start)
		return (FALSE);
	file_len = 0;
	while (start[file_len] && is_space(start[file_len]) == FALSE)
		file_len++;
	ms->parse.oustr = malloc(file_len + 1);
	if (!ms->parse.oustr)
		return (FALSE);
	ft_memcpy(ms->parse.oustr, start, file_len);
	ms->parse.oustr[file_len] = '\0';
	return (TRUE);
}

char	*remove_file(char	*old)
{
	char	*start;
	char	*new;
	int		len;

	start = ft_strstr(old, ">");
	len = start - old;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, old, len);
	new[len] = '\0';
	return (new);
}

void	parse_outfile(t_ms *ms)
{
	char	*old_input;

	if (get_file_name(ms) == FALSE)
		return ;
	old_input = ms->input;
	ms->input = remove_file(old_input);
	if (!ms->input)
		return (ms->input = old_input, (void) 0);
	free(old_input);
}
