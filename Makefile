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
	@gcc $(FLAG) -c $(SRCS)
	@gcc $(FLAG) -o $(NAME) $(OBJS) $(LIB)
	@echo "\033[32mminishell.......[OK]\033[0m"

clean:
	@rm -f $(OBJS)
	@make clean -C libft
	@echo "\033[31mminishell.......[clean]\033[0m"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@make fclean -C libft
	@echo "\033[31mminishell.......[fclean]\033[0m"

re: fclean all	
