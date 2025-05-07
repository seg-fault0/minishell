SRCS =	srcs/main.c				\
		srcs/exit.c				\
		srcs/libft/ft_split.c	\
		srcs/libft/ft_mem.c

# Convert srcs/*.c → objs/*.o, preserving subdirs
OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= minishell
I		= -I includes/
L		= -lreadline -lc

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(L) -o $(NAME)

# Rule to compile .c → .o (handles subdirectories)
objs/%.o: srcs/%.c includes/minishell.h | objs/
	@mkdir -p $(@D)  # Create subdirs in objs/ (e.g., objs/libft/)
	cc -c $(I) $< -o $@

# Ensure objs/ exists
objs/:
	mkdir -p objs

clean:
	rm -rf objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re