##
## EPITECH PROJECT, 2017
## PSU_my_printf
## File description:
## A makefile for my_printf
##

CC	=	gcc -I.

NAME	=	libmy.a

SRCS	=	src/printf.c			\
		src/linked_list.c		\
		src/my_put_nbr.c		\
		src/nbr/my_put_nbr_binary.c	\
		src/nbr/my_put_nbr_hexa.c	\
		src/nbr/my_put_nbr_hexaup.c	\
		src/nbr/my_put_nbr_octal.c	\
		src/nbr/my_put_nbr_unsigned.c	\
		src/nbr/my_put_ptr.c		\
		src/my_getnbr.c			\
		src/tools/my_strlen.c		\
		src/tools/my_strcomp.c		\

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	mkdir -p ../../include/
	cp my.h ../../include/

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
