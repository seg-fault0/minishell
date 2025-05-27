SRCS =	srcs/core/main.c				\
		srcs/core/init_ms.c				\
		srcs/core/luncher.c				\
		srcs/core/err.c					\
		srcs/core/reseter.c				\
		srcs/core/exit.c				\
		srcs/core/signals.c				\
		srcs/builtin/main.c				\
		srcs/builtin/chdir.c			\
		srcs/builtin/echo.c				\
		srcs/builtin/env.c				\
		srcs/builtin/exit.c				\
		srcs/builtin/export.c			\
		srcs/builtin/pwd.c				\
		srcs/builtin/unset.c			\
		srcs/exe/init.c					\
		srcs/exe/fd_manager.c			\
		srcs/exe/exe.c					\
		srcs/exe/main.c					\
		srcs/parsing/main.c				\
		srcs/parsing/helper.c			\
		srcs/parsing/parse_outfile.c	\
		srcs/parsing/parse_infile.c		\
		srcs/parsing/parse_cmd.c		\
		srcs/parsing/extract_cmd.c		\
		srcs/parsing/expand_vars.c		\
		srcs/libft/ft_split.c			\
		srcs/libft/ft_mem.c				\
		srcs/libft/str.c				\
		srcs/libft/ft_split_len.c		\
		srcs/libft/alpha.c				\
		srcs/libft/ft_putnbr.c			\
		srcs/libft/ft_atoi.c			\
		srcs/other/checkers.c			\
		srcs/other/arr_utils.c			\
		srcs/other/free.c				\
		srcs/other/utils.c				\
		srcs/other/char.c				\
		srcs/other/str.c				\
		srcs/gnl/get_next_line.c		\
		srcs/gnl/get_next_line_utils.c	\
		srcs/synthax/main.c				\
		srcs/synthax/quotes.c			\
		srcs/synthax/pipe.c				\
		srcs/fds/main.c					\
		srcs/fds/infd.c					\
		srcs/fds/oufd.c					\

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