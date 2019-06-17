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
    int     k;
    tetri   *base_tetri;
    tetri	*tetri;

    index = 0;
    l = 0;
    x = 0;
    y = 0;
    k = 0;
    tetri = NULL;
    while (str[l] == '\0' && str[l - 1] == '\n')
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
        if (str[l] == '\n' && str[l + 1] == '\n')
        {
            tetri_add_w_copy(&base_tetri, tetri, k++);
            l++;
        }
        y++;
        l++;
        x = 0;
    }
    return (base_tetri);
}

int		reading(int fd)
{
	int		count;
	char	str[546];
	char    *tmp;
	tetri	*base_tetri;
	int i;

	base_tetri = NULL;
	i = 0;
	while ((count = read(fd, str, 546)) >= 20)//читаем 21 символ т/к (..#.\n)5х4 (один блок) + еще один \n ?? Работает, собирает цепь из фигур корректно (вроде)
    {
        str[count] = '\0';
        //tmp = strcut(str);  //?
        if (main_validate(str, ft_strlen(str) + 1) == -1)
            return (-1);
        base_tetri = detect_and_createtetri(str);
        /*while (base_tetri->x[i])
        {
            printf("%d\n", base_tetri->x[i]);
            i++;
        }
        i = 0;*/
		free(base_tetri);
		free(tmp);
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