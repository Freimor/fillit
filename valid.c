/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 16:22:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "fillit.h"
#include <stdio.h>

char	**analize(char *str)
{
	block   mass;
	int		i;
	int		j;
	int     k;
	int     l;

	ptr = &s;
	i = 0;
	while (*str != '\0' && k != TETRI)
	{
	    j = 0;
		if (*str != '\n' && l != 4)
		{
			if (*str == '#')
			{
                cube.x = i;
                cube.y = j;
                masse[k][l] = cube;
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
	return (ptr);
}

int main(void)
{
	char	*str;
    block	**w;
    char    *tmp;
	int		i;
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	str = ft_strnew(1);
	fd = open("/Users/sskinner/gitex/Fillit/tetri.txt", O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
	    buf[ret] = '\0';
	    tmp = ft_strjoin(str, buf);
	    free(str);
	    str = tmp;
		i++;
	}
	w = analize(str);
	i = 0;

	return (0);
}*/