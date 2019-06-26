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
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCSSS:%.c=%.o)
INC_DIR	= includes/
LIB = libft/libft.a

SRCSSS 	=	src/fillit_funk.c src/fillit_funk_2.c src/main.c src/map_funk.c \
			src/tetri_funk.c src/valid.c \

all: $(NAME)

$(NAME):$(OBJS) $(LIB) | build
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

$(OBJS):$(LIB)
	gcc $(FLAGS) -c $(SRCSSS)

$(LIB):
	make -C ./libft
	make clean -C ./libft

build:
	mkdir obj

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re:
	fclean all