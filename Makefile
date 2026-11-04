NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
SRCES = ft_printf.c \
		hexadecimal.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putchar_fd.c\
		unsigned_putnbr.c\
		print_hex.c\
		main.c
OBECTS = $(SRCES:.c=.o)

all: $(NAME)
$(NAME):$(OBECTS)
	$(AR) $(NAME) $(OBECTS)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re