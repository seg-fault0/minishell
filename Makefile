SRCS =	srcs/core/main.c				\
		srcs/core/init_ms.c				\
		srcs/core/luncher.c				\
		srcs/core/err.c					\
		srcs/core/reseter.c				\
		srcs/core/exit.c				\
		srcs/signals/ms_signals.c		\
		srcs/signals/heredoc_signal.c	\
		srcs/builtin/main.c				\
		srcs/builtin/chdir.c			\
		srcs/builtin/echo.c				\
		srcs/builtin/env.c				\
		srcs/builtin/exit.c				\
		srcs/builtin/export.c			\
		srcs/builtin/pwd.c				\
		srcs/builtin/unset.c			\
		srcs/exe/exit_code.c			\
		srcs/exe/fd_manager.c			\
		srcs/exe/exe.c					\
		srcs/exe/init.c					\
		srcs/exe/main.c					\
		srcs/parsing/main.c				\
		srcs/parsing/remove_files.c		\
		srcs/parsing/helper.c			\
		srcs/parsing/parse_outfile.c	\
		srcs/parsing/parse_infile.c		\
		srcs/parsing/parse_cmd.c		\
		srcs/parsing/extract_cmd.c		\
		srcs/parsing/expand_vars.c		\
		srcs/parsing/heredoc_expand.c	\
		srcs/parsing/epand_vars_helper.c\
		srcs/libft/ft_split.c			\
		srcs/libft/ft_mem.c				\
		srcs/libft/str.c				\
		srcs/libft/ft_split_len.c		\
		srcs/libft/alpha.c				\
		srcs/libft/ft_putnbr.c			\
		srcs/libft/ft_atoi.c			\
		srcs/libft/ft_itoi.c			\
		srcs/other/checkers.c			\
		srcs/other/checkers2.c			\
		srcs/other/arr_utils.c			\
		srcs/other/arr_utils2.c			\
		srcs/other/free.c				\
		srcs/other/utils.c				\
		srcs/other/char.c				\
		srcs/other/str.c				\
		srcs/synthax/main.c				\
		srcs/synthax/operators.c		\
		srcs/synthax/op_counter.c		\
		srcs/synthax/redir.c			\
		srcs/synthax/quotes.c			\
		srcs/synthax/pipe.c				\
		srcs/fds/here_doc.c				\
		srcs/fds/infd.c					\
		srcs/fds/oufd.c					\
		srcs/fds/main.c					\

# Convert srcs/*.c → objs/*.o, preserving subdirs
OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= minishell
FLAGS	= -Wall -Wextra -Werror -g
I		= -I includes/
L		= -lreadline -lc

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(L) -o $(NAME)

# Rule to compile .c → .o (handles subdirectories)
objs/%.o: srcs/%.c includes/minishell.h | objs/
	@mkdir -p $(@D)  # Create subdirs in objs/ (e.g., objs/libft/)
	cc -c $(I) $(FLAGS) $< -o $@

# Ensure objs/ exists
objs/:
	mkdir -p objs

clean:
	rm -rf objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

valgrind : all
	valgrind --leak-check=full --trace-children=yes --track-fds=yes --log-file=log.txt ./minishell