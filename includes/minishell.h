/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:22:22 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 11:00:21 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PURPLE "\033[0;35m"
# define RESET  "\033[0m"
# define PROMPT PURPLE "minishell : " RESET

# define TRUE 1
# define FALSE 0
# define BOOL unsigned sort

void	ft_exit();

#endif