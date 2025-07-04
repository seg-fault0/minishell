/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:22:22 by wimam             #+#    #+#             */
/*   Updated: 2025/07/03 03:26:04 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "minishell : "
# define HERE_DOC "> "

# define PTH "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

# define GNL_BUFFER_SIZE 1
# define MAX_CMD 500
# define MAX_FD 62

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
# define ERR_OPEN_F 8
# define ERR_THIS_IS_DIR 9
# define ERR_CMD_NF 10

typedef struct s_parsed
{
	char	**tmp2d;
	char	***cmd;
	char	***infiles;
	char	***oufiles;
	int		cmd_nbr;
}t_parsed;

typedef struct s_cmd
{
	char	**paths;
	char	***cmd;
	int		*pids;
	int		cur_exit_code;
	int		last_exit_code;
	int		counter;
	int		max_counter;
}t_cmd;

typedef struct s_fd
{
	int		*out;
	int		*in;
	size_t	*append;
	size_t	*heredoc;
}t_fd;

typedef struct s_ms
{
	t_cmd		cmd;
	t_parsed	parse;
	t_fd		fd;
	char		**env;
	char		*cwd;
	char		*input;
}t_ms;

typedef struct s_expand_state
{
	int		i;
	int		start;
	char	*result;
}	t_expand_state;

//core
BOOL	init_struct(t_ms *ms, char **env);
void	ft_luncher(t_ms *ms);
void	ft_exit(t_ms *ms);
void	err_msg(int msg);
void	reset_prompt(t_ms *ms);

//signals
void	minishell_signals(t_ms *ms);
void	heredoc_signals(int *pfd);

//parse
void	ft_parse(t_ms *ms);
void	parse_outfile(t_ms *ms);
void	parse_infile(t_ms *ms);
void	parse_cmd(t_ms *ms);
char	**split_cmd(const char *input);
int		cmd_counter(const char *str);
BOOL	synthax_checker(char *input);
BOOL	is_redirection(char c);
int		skip_redirection(char *cmd, int i);
char	*extract_cmd(char *cmd);
void	expand_vars(t_ms *ms);
char	*extract_first_missing_filename(char *s);
char	*expand_line_heredoc(t_ms *ms, char *str);
char	*heredoc_expand(t_ms *ms, char *line);
void	ft_delimiter_extract(char *delimiter);
int		is_in_single_quotes(const char *str, int pos);
BOOL	is_ft(const char *str);
BOOL	is_in_assignment(const char *str, int pos);
char	*wrap_if_needed(char *var_value, char *str, int i);
char	*extract_and_expand_var(t_ms *ms, char *str, int *i);
char	*ft_ft(char	*str);
BOOL	handle_digit_after_dollar(char *str, t_expand_state *st);
void	handle_valid_var_expand(t_ms *ms, char *str, t_expand_state *st);
char	*append_before(char *res, char *str, int start, int end);

//fds
void	fd_setup(t_ms *ms);
void	in_fd_opener(t_ms *ms);
void	ou_fd_opener(t_ms *ms);
int		here_doc(t_ms *ms, char *delimiter);

//reseter
void	parse_reseter(t_ms *ms);
void	cmd_reseter(t_ms *ms);
void	fd_reseter(t_ms *ms);

//exe
void	init_cmd(t_ms *ms);
void	ft_exe(t_ms *ms);
void	ft_start(t_ms *ms, int rfd);
void	fd_manager(t_ms *ms, int rfd, int *pfd);
int		get_exit_code(t_ms *ms);
void	ft_wait(t_ms *ms);

//env
char	*get_env(char **env, char *look_for);
void	set_env(t_ms *ms);
void	unset_env(t_ms *ms);
void	print_arr(char **arr);

//builtin cmds
void	builtin_exe(t_ms *ms, char *cmd);
void	built_in_exit(t_ms *ms);
void	ft_echo(t_ms *ms);
void	ft_pwd(t_ms *ms);
void	ft_chdir(t_ms *ms);
void	env(t_ms *ms);

//utils
void	free2(char **arr, int c);
void	free3(char ***arr, int c);
size_t	char_counter(const char *str, int c);
void	close_pipe(int *fd);
void	ft_close(int fd);

//array utils
char	**get_2darr_cp(char **arr);
char	**add_to_arr(char **arr, char *to_add);
char	**extract_from_arr(char **arr, char *to_extract);
void	sort_arr(char **arr);
int		get_arr_size(char **arr);
void	print_arr(char **arr);

//checkers
BOOL	is_builtin(char	*str);
BOOL	is_main_process_exe(char *cmd);
BOOL	is_space(int c);
BOOL	is_quote(char c);
BOOL	is_digit(int c);
BOOL	is_dir(const char *path);
BOOL	is_file(const char *path);
BOOL	sigint_trigered(t_ms *ms);
BOOL	stdout_file_checker(char **arr);
BOOL	outrange_long(char *str);

//synthax
BOOL	open_quotes_checker(char *input);
BOOL	open_pipe_checker(char *input);
BOOL	operators_checker(char *input);
BOOL	open_redir_checker(char *input);
BOOL	op_counter(char *input);

//libft
char	**ft_split(char const *s, char c);
char	*ft_strstr(char *haystack, char *needle);
BOOL	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split_len(const char *s, char c, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalnum(int c);
void	ft_putnbr(int n);
long	ft_atoi(const char *str);
char	*ft_itoa(int n);
int		diff_strcmp(const char *s1, const char *s2);

//char utils
BOOL	char_search(char *str, char c);

//mem utils
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

//other
int		skip_space(char *str);
void	free3size(char ***arg, int size);
#endif