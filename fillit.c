/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 17:18:47 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static tetri	*tetri_build(tetri **base, int k, int x, int y)
{
	if (*base == NULL)
	{
        if (!(*base = (tetri *)malloc(sizeof(tetri))))
            return (NULL);
        (*base)->b1.x = x;
        (*base)->b1.y = y;
        return (*base);
	}
	else
	{
		if (k == 2)
		{
            (*base)->b2.x = x;
            (*base)->b2.y = y;
        }
        if (k == 3)
        {
            (*base)->b3.x = x;
            (*base)->b3.y = y;
        }
        if (k == 4)
        {
            (*base)->b4.x = x;
            (*base)->b4.y = y;
        }
    }
	return (*base);
}

static tetri   *detect_and_createtetri(char *str)
{
    int		x;
    int		y;
    int		index;
    int		l;
    tetri	*tetri;

    index = 1;
    l = 0;
    x = 1;
    y = 1;
    tetri = NULL;
    while (str[l] != '\0')
    {
        while (str[l] != '\n')
        {
            if (str[l] == '#')
            {
                tetri_build(&tetri, index, x, y); //собирается 4 блока, неплохо бы сдесь засунуть в tetri
                index++;
            }
            l++;
            x++;
        }
        y++;
        l++;
        x = 1;
    }//свернуть 4 блока в struct tetri | 3 уровня : пиксель->блок->тетримино
    return (tetri);
}

int		reading(int fd)
{
	int		count;
	char	str[21];
	tetri   *base_tetri;
	tetri	*buf_tetri;

	base_tetri = NULL;
	while ((count = read(fd, str, 21)) >= 20)//читаем 21 символ т/к (..#.\n)5х4 (один блок) + еще один \n ?? Работает, собирает цепь из фигур корректно (вроде)
	{
		str[20] = '\0';
		buf_tetri = detect_and_createtetri(str);
		tetri_add_w_copy(&base_tetri, buf_tetri); //функция должна копить тетри в лист tetri_add_w_copy
		free(buf_tetri);
	}
    return (1);
}

int main ()
{
	int fd;
	
	fd = open("/Users/sskinner/gitex/Fillit/tetri.txt", O_RDONLY);
	reading(fd);
	return (0);
}