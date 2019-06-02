/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 17:50:04 by sskinner         ###   ########.fr       */
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
	int index;             //ненужны, сразу кидать в tetri на этапе read
	struct block	*next; //
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

#endif