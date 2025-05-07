/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:22:22 by wimam             #+#    #+#             */
/*   Updated: 2025/05/07 12:25:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PURPLE "\033[0;35m"
# define RESET  "\033[0m"
# define PROMPT PURPLE "minishell : " RESET

# define BOOL unsigned short
# define TRUE 1
# define FALSE 0

typedef struct s_cmd
{
	char	**paths;
	char	***cmd;
}t_cmd;

typedef struct s_ms
{
	t_cmd		cmd;
	char		**env;
	char		*input;
}t_ms;

//core
BOOL	init_struct(t_ms *ms, char **env);
void	ft_luncher(t_ms *ms);
void	ft_exit(t_ms *ms);

//utils
void	free2(char **arr);

//libft
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif