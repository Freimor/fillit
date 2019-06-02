/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 17:02:37 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static block	*block_create(block **base, int index)
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
}

int		reading(int fd)
{
	int		count;
	int		i;
	int		j;
	int		k;
	int		l;
	char	*str[21];
	block	*tetri;
	block	*base;
	
	
	count = read(fd, str, 20);             //читаем 21 символ т/к (..#.\n)5х4 (один блок)
	str[21] = '\0';
	k = 0;
	l = 0;
	while (str[l] != '\0')
	{
	    j = 0;
		if (str[l] != '\n')
		{
			if (str[l] == '#')
			{
				tetri = block_create(base, k);
				tetri->x = i;
				tetri->y = j;
				k++;
			}
			l++;
			i++;
		}
		k++;
		j++;
		l++;
		i = 0;
	}
}
