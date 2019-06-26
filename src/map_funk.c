/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 19:36:28 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		to_map(t_fig *list, int disp[2], char **map)
{
	int		*x;
	int		*y;
	int		i;
	char	c;

	i = 0;
	x = list->x_arr;
	y = list->y_arr;
	c = list->index + 65;
	while (i < 4)
	{
		map[y[i] + disp[1]][x[i] + disp[0]] = c;
		i++;
	}
}

int			min_edge(t_fig *list)
{
	int a;
	int n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	a = 0;
	while (a * a < 4 * n)
		a++;
	return (a);
}

char		**zero_map(int a)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = ft_memalloc((a + 2) * sizeof(char *));
	while (j < a + 1)
	{
		map[j] = ft_memalloc((a + 2) * sizeof(char));
		j++;
	}
	j = 0;
	while (j < a)
	{
		map[j] = ft_memset(map[j], '.', a);
		j++;
	}
	return (map);
}

char		*free_map(char **map)
{
	int i;

	i = ft_strlen(map[0]);
	while (i + 1 > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	return (NULL);
}

void		print_map(char **map)
{
	int j;

	j = 0;
	while (map[j])
	{
		ft_putstr(map[j]);
		ft_putchar('\n');
		j++;
	}
}
