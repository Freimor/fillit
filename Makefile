# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 19:29:34 by sskinner          #+#    #+#              #
#    Updated: 2019/06/26 20:05:40 by sskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror -pedantic -std=c99
OBJS = $(SRCS:%.c=%.o)

SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./lib

SRC1 =	fillit_funk.c fillit_fink_2.c main.c map_funk.c tetri_funk.c valid.c \

all: $(NAME)

$(NAME):$(OBJS) | lib
	gcc $(FLAGS) -o $(NAME) -L ./libft/libft.h $(OBJS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c


$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJS)  -o $(NAME)

lib:
	$(MAKE) -C ./libft
	$(MAKE) clean -C ./libft

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) re --no-print-directory

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all