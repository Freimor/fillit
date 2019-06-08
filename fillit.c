/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/08 17:25:15 by sskinner         ###   ########.fr       */
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

static int validate(char *str)
{
	int	i;
	int	j;
	int	k;
	int	stack[8]; //1 tetri = 8 coordinates

	i = 0;
	j = 0;
	k = 0;
	while (*str != '\0')
	{
		if (i > 20) //??
			return (-1);
		while (*str != '\n')
		{
			if (*str != '.' && *str != '#' /* && *str != '\n' && *str != '\0'*/) //не так должно быть
				return (-1);
			else if (*str == '#')
			{
				stack[k] = i;
				stack[k++] = j;
				k++;
			} 
			str++;
			j++;
		}
		if (j != 4)
			return (-1);
		j = 0;
		i = i + 4;
	}
	k = 0;
	while (k < 6) //??
	{
		if ((stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == 1 || -1) || //можно ли так
		(stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == 1 || -1))
			k = k + 2;
		else
			return (-1);	
	}
	return (0);
}

int		reading(int fd)
{
	int		count;
	char	str[21];
	tetri	*base_tetri;
	tetri	*buf_tetri;

	base_tetri = NULL;
	while ((count = read(fd, str, 21)) >= 20)//читаем 21 символ т/к (..#.\n)5х4 (один блок) + еще один \n ?? Работает, собирает цепь из фигур корректно (вроде)
	{
		str[20] = '\0';
		buf_tetri = detect_and_createtetri(str);
		tetri_add_w_copy(&base_tetri, buf_tetri); //функция должна копить тетри в лист tetri_add_w_copy
		validate; //неоч проверять блоки после создания
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