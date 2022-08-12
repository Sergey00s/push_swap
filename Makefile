NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = algorithm.c argchcks.c indexing.c listutils.c main.c secalgo.c sorting.c utilstwo.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C ft_printf
	$(CC) $(OBJ) ft_printf/libftprintf.a libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	make clean -C ft_printf
	rm -rf $(NAME)

norm:
	@norminette *.[ch] | grep ': OK!' -v || printf '\nAll true!\n\n'

re: fclean all

.PHONY: all clean fclean re norm