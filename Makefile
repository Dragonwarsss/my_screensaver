##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -Iinclude -lm -Wattributes -o2

NAME	=	my_screensaver

SRCS	=	src/main.c		\
		src/init.c		\
		src/select_screen.c	\
		src/fill_struct_1.c	\
		src/screen_1.c		\
		src/screen_2.c		\
		src/screen_3.c		\
		src/screen_4.c		\
		src/screen_5.c		\
		src/print_usage.c	\
		src/free_everything.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -Llib/my/ -lmy

all:	libs $(NAME)

libs:
	$(MAKE) -C lib/pixel/ OUTDIR=.
	$(MAKE) -C lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -Llib/pixel/ -lpixel -lc_graph_prog
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/pixel/
	$(MAKE) clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/pixel/
	$(MAKE) fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re
