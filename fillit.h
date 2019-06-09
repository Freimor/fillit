/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/09 15:22:52 by sskinner         ###   ########.fr       */
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

typedef struct		tetri
{
	int	*x;
	int	*y;
	struct tetri *next;
}					tetri;

tetri	*tetri_new();
int		tetri_del(tetri **base, tetri *del);
void	tetri_add(tetri **base, tetri *new);
void	tetri_add_w_copy(tetri **base, tetri *new);
int     main_validate(char *str, int count);

#endif