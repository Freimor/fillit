/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:10 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		to_map(t_fig *list, int dx, int dy, char **map)
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
		map[y[i] + dy][x[i] + dx] = c;
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
	int		j;
	char	**map;

	j = 0;
	if (!(map = malloc((a + 1) * sizeof(char *))))
		return (NULL);
	map[a] = NULL;
	while (j < a)
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
