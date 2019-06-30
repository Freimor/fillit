# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 19:29:34 by sskinner          #+#    #+#              #
#    Updated: 2019/06/26 20:52:03 by sskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = fillit.h
OBJS = $(SRCSSS:%.c=%.o)
INC_DIR	= includes/
LIB = libft/libft.a

SRCSSS 	=	src/fillit_funk.c src/fillit_funk_2.c src/main.c src/map_funk.c \
			src/tetri_funk.c src/valid.c \

OBJS	=	fillit_funk.o fillit_funk_2.o main.o map_funk.o \
			tetri_funk.o valid.o \

all: $(NAME)

$(NAME):$(OBJS) $(LIB)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):$(LIB)
	gcc -Wall -Wextra -Werror -c $(SRCSSS) -I includes/fillit.h -I libft/libft.h

$(LIB):
	make -C ./libft
	make fclean -C ./libft
	make -C ./libft

clean:
	rm -f $(OBJS)
	make fclean -C ./libft

fclean: clean
	rm -f $(NAME)

re:fclean all

norm:
	norminette *.c *.h