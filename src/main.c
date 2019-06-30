/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:29:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		fill_map(int a, t_fig *list, char **map)
{
	int dx;
	int dy;

	dy = 0;
	while (dy < a)
	{
		dx = 0;
		while (dx < a)
		{
			if (check_avail(list, dx, dy, map))
			{
				to_map(list, dx, dy, map);
				if (list->next == NULL || fill_map(a, list->next, map))
					return (1);
				else
					clear_tetr(list, dx, dy, map);
			}
			dx++;
		}
		dy++;
	}
	if (list->index == 0)
		return (-1);
	return (0);
}

t_fig	*validate_main(char *str, int count)
{
	char	*buf_str;
	t_fig	*list;
	int		i;
	int		l;

	l = 0;
	list = NULL;
	buf_str = NULL;
	if (str == NULL)
		return (NULL);
	if (count % 21 != 0)
		return (NULL);
	i = 0;
	while (1)
	{
		buf_str = ft_strsub(str, i, 21);
		i = i + 21;
		l++;
		if ((list = validate_sub(buf_str, l)) == NULL)
			return (NULL);
		if (str[i - 1] == '\0' && str[i - 2] == '\n')
			break ;
	}
	return (list);
}

int		main(int ac, char **av)
{
	t_fig	*list;
	char	**map;
	char	*str;
	int		a;

	if ((str = reading(ac, av[1])) == NULL)
	{
		free(str);
		ft_putendl("error");
		return (0);
	}
	if ((list = validate_main(str, ft_strlen(str) + 1)) == NULL)
	{
		free(str);
		ft_putendl("error");
		return (0);
	}
	free(str);
	tetri_absolute(&list);
	a = min_edge(list);
	map = create_map(list, a);
	print_map(map);
	free_map(map);
	tetri_del(&list);
}
