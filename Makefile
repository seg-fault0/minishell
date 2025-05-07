SRCS    = srcs/main.c

OBJS    = $(SRCS:srcs/%.c=objs/%.o)

NAME    = minishell

I       = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

objs/%.o: srcs/%.c includes/minishell.h | objs/
	cc -c $(I) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re