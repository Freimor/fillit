/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 18:17:20 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*static block	*block_create(block **base, int index)
{
	block *s;

	if (*base == NULL)
	{
		*base = block_new(0,0,0);
		return (*base);
	}
	if ((s = block_check(base, index)) == 0)
	{
		s = block_new(0,0, index);
		block_add(base, s);
	}
	return (s);
}*/

static tetri	*tetri_build(tetri **base, block pixel, int k)
{
	if (*base == NULL)
	{
		*base = tetri_new(pixel, 0, 0, 0);
		return (*base);
	}
	else
	{
		if (k = 2)
			(*base)->b2 = pixel;
		if (k = 3)
			(*base)->b3 = pixel;
		if (k = 4)
			(*base)->b4 = pixel;
	}
	return (*base);
}

int		reading(int fd)
{
	int		count;
	int		x;
	int		y;
	int		index;
	int		l;
	char	*str[21];
	block	pixel;
	block	*base_block;
	tetri	*base_tetri;
	tetri	*figure;
	
	
	while ((count = read(fd, str, 21)) > 20)//читаем 21 символ т/к (..#.\n)5х4 (один блок) + еще один \n
	{
		str[21] = '\0';
		index = 0;
		l = 0;
		x = 0;
		y = 0;
		while (str[l] != '\0')
		{
			if (str[l] != '\n')
			{
				if (str[l] == '#')
				{
					pixel.x = x;
					pixel.y = y;
					figure = tetri_build(base_tetri, pixel, index); //собирается 4 блока, неплохо бы сдесь засунуть в tetri
					index++;
				}
				l++;
				x++;
			}
			y++;
			l++;
			x = 0;
		}//свернуть 4 блока в struct tetri | 3 уровня : пиксель->блок->тетримино
		///////////////
	}
}
