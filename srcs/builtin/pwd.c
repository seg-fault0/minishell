/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:43:07 by wimam             #+#    #+#             */
/*   Updated: 2025/06/27 03:50:39 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_ms *ms)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		printf("%s\n", ms->cwd);
	else
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	ms->cmd.cur_exit_code = 0;
}
