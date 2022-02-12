# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 22:23:02 by avalerio          #+#    #+#              #
#    Updated: 2022/01/21 23:12:02 by avalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	map_read.c map_draw.c line_draw.c main.c
SRCDIR	=	./src/
SRCS	=	$(addprefix $(SRCDIR), $(FILES))
OBJS	=	${SRCS:.c=.o}
NAME	=	fdf
INCLUDE	=	-I includes -I libft
MODULE	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -lm
MLXFLAG	=	-lmlx -lX11 -lXext
RM		=	rm -f
LEAKS	=	valgrind
LEAKS_FILE	= leak-out.txt
LEAKS_FLAG	= --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--verbose --log-file=$(LEAKS_FILE) ./fdf maps/basictest.fdf

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(MODULE):
	make bonus -C libft

$(NAME):	$(MODULE) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAG) $(MODULE) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean:     clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

leaks:
	$(LEAKS) $(LEAKS_FLAG)

lclean:
	$(RM) $(LEAKS_FILE)

.PHONY: all clean fclean re