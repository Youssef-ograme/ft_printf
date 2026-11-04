NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRC = src
SRCES = $(SRC)/ft_printf.c \
		$(SRC)/hexadecimal.c\
		$(SRC)/ft_putnbr_fd.c\
		$(SRC)/ft_putstr_fd.c\
		$(SRC)/ft_putchar_fd.c\
		$(SRC)/unsigned_putnbr.c\
		$(SRC)/print_hex.c

INC = includes
LIB = -I includes	
OBECTS = $(SRCES:.c=.o)

all: $(NAME)
$(NAME):$(OBECTS)
	$(AR) $(NAME) $(OBECTS)

%.o:%.c $(INC)/ft_printf.h
	$(CC) $(CFLAGS) $(LIB) -c $< -o $@

clean:
	$(RM) $(OBECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

