/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 16:38:40 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		reading(int fd)
{
	int		count;
	int		i;
	int		j;
	int		k;
	int		l;
	char	*str;
	block	*tetri;
	
	
	count = read(fd, str, 21);
	
	while (*str != '\0' && k != TETRI)
	{
	    j = 0;
		if (*str != '\n' && l != 4)
		{
			if (*str == '#')
			{
                tetri->x = i;
                tetri->y = j;
                tetri = tetri->next;
                l++;
            }
			str++;
			i++;
		}
		k++;
		j++;
		str++;
		l = 0;
		i = 0;
	}
}
