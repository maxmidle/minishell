NAME = minishell

INCLUDE = minishell.h

FLAG = -Wall -Wextra -Werror

SRCS = minishell.c run_bin.c read_line.c tilde.c env.c env_verif.c cd.c echo.c \
	dollar.c run_cmd.c

OBJS = $(SRCS:.c=.o)

LIB = -L libft -lft

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft
	gcc $(FLAG) -c $(SRCS)
	gcc $(FLAG) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all	
