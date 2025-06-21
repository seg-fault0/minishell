/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 07:44:44 by wimam             #+#    #+#             */
/*   Updated: 2025/06/21 07:51:56 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_expand(char *line)
{
	if (!line || !ft_strstr(line, "$"))
		return (line);
	else
		return (free(line), ft_strdup("expended line\n"));
}
