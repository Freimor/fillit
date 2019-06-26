/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_funk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:41:57 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 19:35:46 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		fill_map(int a, t_fig *list, char **map)
{
	int	disp[2];
	int	*x;
	int	*y;

	disp[0] = list->x_arr;
	disp[1] = list->y_arr;
	disp[1] = -1;
	while (++disp[1] < a)
	{
		disp[0] = -1;
		while (++disp[0] < a)
		{
			if (check_avail(x, y, disp, map))
			{
				to_map(list, disp, map);
				if (list->next == NULL || fill_map(a, list->next, map))
					return (1);
			}
		}
	}
	if (list->index == 0)
		return (-1);
	return (0);
}

int		check_avail(int *x, int *y, int disp[2], char **map)
{
	int	i;
	int	nx;
	int	ny;

	i = 0;
	while (i < 4)
	{
		nx = x[i] + disp[0];
		ny = y[i] + disp[1];
		if (map[ny][nx] == '.')
			i++;
		else if (map[ny][nx] != '.')
			return (0);
	}
	return (1);
}

int		func_flag(const int vis[8], int *stack)
{
	int k;
	int flag;

	k = 0;
	flag = 0;
	while (k < 4)
	{
		if ((vis[0] == stack[k]) && (vis[1] == stack[k + 4]))
			flag++;
		if ((vis[2] == stack[k]) && (vis[3] == stack[k + 4]))
			flag++;
		if ((vis[4] == stack[k]) && (vis[5] == stack[k + 4]))
			flag++;
		if ((vis[6] == stack[k]) && (vis[7] == stack[k + 4]))
			flag++;
		k++;
	}
	return (flag);
}

int		getvid(int *stack, int i)
{
	int	flag;
	int	vis[8];

	vis[0] = stack[i] + 1;
	vis[1] = stack[i + 4];
	vis[2] = stack[i];
	vis[3] = stack[i + 4] + 1;
	vis[4] = stack[i] - 1;
	vis[5] = stack[i + 4];
	vis[6] = stack[i];
	vis[7] = stack[i + 4] - 1;
	flag = func_flag(vis, stack);
	return (flag);
}

char	**create_map(t_fig *list, int a)
{
	char	**map;
	int		f;

	map = zero_map(a);
	f = fill_map(a, list, map);
	if (f == 1)
		return (map);
	else if (f == -1)
	{
		free_map(map);
		return (create_map(list, a + 1));
	}
	return (map);
}
