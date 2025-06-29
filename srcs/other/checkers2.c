/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:55:21 by wimam             #+#    #+#             */
/*   Updated: 2025/06/30 00:01:11 by wimam            ###   ########.fr       */
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

BOOL	sigint_trigered(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->parse.cmd_nbr)
		if (ms->fd.in[i++] == -130)
			return (TRUE);
	return (FALSE);
}

BOOL	stdout_file_checker(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (diff_strcmp(arr[i], "/dev/stdout") != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL	outrange_long(char *str)
{
	int		sign;
	char	*max;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!str)
		return (TRUE);
	if (ft_strlen(str) > 19)
		return (TRUE);
	if (ft_strlen(str) < 19)
		return (FALSE);
	if (sign == -1)
		max = "9223372036854775808";
	else
		max = "9223372036854775807";
	if (ft_strncmp(str, max, 19) > 0)
		return (TRUE);
	return (FALSE);
}
