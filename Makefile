SRCS	= srcs/main.c

OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= minishell

I		= -I includes/

L		= -lreadline -lc

all: $(NAME)

$(NAME): $(OBJS)
	cc $< $(L) -o $@

objs/%.o: srcs/%.c includes/minishell.h | objs/
	cc -c $(I) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re