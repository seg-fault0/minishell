/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 07:44:44 by wimam             #+#    #+#             */
/*   Updated: 2025/06/25 10:43:08 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_expand(t_ms *ms, char *line)
{
	char	*expanded;

	if (!line || !ft_strchr(line, '$'))
		return (line);
	expanded = expand_line_heredoc(ms, line);
	free(line);
	return (expanded);
}
