SRCS =	srcs/core/main.c				\
		srcs/core/init_ms.c				\
		srcs/core/luncher.c				\
		srcs/core/err.c					\
		srcs/core/exit.c				\
		srcs/cmd/init.c					\
		srcs/cmd/builtin.c				\
		srcs/cmd/env.c					\
		srcs/cmd/exe.c					\
		srcs/parsing/pars.c				\
		srcs/libft/ft_split.c			\
		srcs/libft/ft_mem.c				\
		srcs/libft/str.c				\
		srcs/other/checkers.c			\
		srcs/other/arr_utils.c			\
		srcs/other/free.c				\
		srcs/other/utils.c				\
		srcs/redirections/setup_fds.c	\

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
