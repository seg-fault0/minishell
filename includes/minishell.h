/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:22:22 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 19:07:04 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "\033[0;35mminishell : \033[0m"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BOOL unsigned short
# define TRUE 1
# define FALSE 0

# define STACK 0
# define HEAP 1

# define ERR_ALLOC_F 1
# define ERR_PIPE_F 2
# define ERR_FORK_F 3
# define ERR_EXECVE_F 4
# define ERR_DUP2_F 5
# define ERR_CHDIR_F 6
# define ERR_PWD_F 7

typedef struct s_parsed
{
	char	***cmd;
	int		cmd_nbr;
}t_parsed;

typedef struct s_cmd
{
	char	**paths;
	char	***cmd;
	int		counter;
	int		max_counter;
}t_cmd;

typedef struct s_ms
{
	t_cmd		cmd;
	t_parsed	parse;
	char		**env;
	const char	*input;
}t_ms;

//core
BOOL	init_struct(t_ms *ms, char **env);
void	ft_luncher(t_ms *ms);
void	ft_exit(t_ms *ms);
void	err_msg(int msg);

//parse
void	ft_parse(t_ms *ms);

//cmd
void	init_cmd(t_ms *ms);
void	ft_exe(t_ms *ms);

//env
char	*get_env(char **env, char *look_for);
void	set_env(t_ms *ms);
void	unset_env(t_ms *ms);

//builtin cmds
void	builtin_exe(t_ms *ms, char *cmd);
void	ft_env(t_ms *ms);
void	ft_chdir(t_ms *ms);

//utils
void	free2(char **arr, int c);
void	free3(char ***arr, int c);
size_t	char_counter(const char *str, int c);
void	close_pipe(int *fd);
void	ft_close(int fd);
char	**get_2darr_cp(char **arr);

//checkers
BOOL	is_builtin(char	*str);
BOOL	is_main_process_exe(char *cmd);

//libft
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
BOOL	ft_strcmp(const char *s1, const char *s2);

#endif