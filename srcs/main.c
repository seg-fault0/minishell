/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:36:25 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 11:24:57 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	ft_luncher()
{
	char	*input;

	while (TRUE)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		add_history(input);
	}
}

BOOL	init_struct(t_ms *ms)
{
	ft_memset(ms, 0, sizeof(t_ms));
	return (TRUE);
}

int main(int ac, char **av, char **env)
{
	t_ms	ms;
	
	(void) ac;
	(void) av;
	(void) env;
	if (init_struct(&ms) == FALSE)
		return (1);
	ft_luncher();
	ft_exit();
}