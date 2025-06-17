/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:55:21 by wimam             #+#    #+#             */
/*   Updated: 2025/06/17 11:04:29 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	is_dir(const char	*path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (FALSE);
	if (S_ISDIR(statbuf.st_mode))
		return (TRUE);
	return (FALSE);
}

BOOL	is_file(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (FALSE);
	if (S_ISREG(statbuf.st_mode))
		return (TRUE);
	return (FALSE);
}
