/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/09 15:23:25 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static tetri	*tetri_build(tetri **base, int index, int x, int y)
{
	if (*base == NULL)
	    *base = tetri_new();
	(*base)->x[index] = x;
	(*base)->y[index] = y;
	return (*base);
}

static tetri   *detect_and_createtetri(char *str)
{
    int		x;
    int		y;
    int		index;
    int		l;
    tetri   *base_tetri;
    tetri	*tetri;

    index = 0;
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
                tetri_build(&tetri, index, x, y);
                index++;
            }
            l++;
            x++;
        }
        if (str[l + 1] == '\n' || str[l + 1] == '\0')
            tetri_add_w_copy(base_tetri, tetri);
        y++;
        l++;
        x = 1;
    }
    return (base_tetri);
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
			if (*str != '.' && *str != '#')
			    if (*str != '\n' && i % 5 == 0)
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
		if ((stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == 1) || //можно ли так
		(stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == -1) ||
		(stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == 1) ||
        (stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == -1))
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
	int i;

	base_tetri = NULL;
	i = 0;
	while ((count = read(fd, str, 546)) >= 20)//читаем 21 символ т/к (..#.\n)5х4 (один блок) + еще один \n ?? Работает, собирает цепь из фигур корректно (вроде)
    {
        str[count] = '\0';
        if (main_validate(str, count) == -1)
            return (-1);
        buf_tetri = detect_and_createtetri(str);
        while (buf_tetri->x[i])
        {
            printf("%d\n", buf_tetri->x[i]);
            i++;
        }
        i = 0;
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