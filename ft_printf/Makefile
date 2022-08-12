NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_putnbr_fd.c \
		ft_putnbr16.c \
		ft_putnbr16x.c \
		ft_putstr_fd.c \
		ft_putunbr.c \
		ft_putchar_fd.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
		
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all