/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 16:13:53 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1
# define TETRI 26

typedef struct		block
{
	int	x;
	int	y;
}					block;

typedef struct		tetri
{
	struct block b1;
	struct block b2;
	struct block b3;
	struct block b4;
	struct tetri *next;
}					tetri;

block	*block_new(int x, int y, int index);
int		block_del(block **base, int index);
void	block_add(block **base, block *new);
block	*block_check(block **base, int index);
tetri	*tetri_new(block b1, block b2, block b3, block b4);
int		tetri_del(tetri **base, tetri *del);
void	tetri_add(tetri **base, tetri *new);
void	tetri_add_w_copy(tetri **base, tetri *new);

#endif