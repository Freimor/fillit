/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:29:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 19:36:21 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

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
	while (!(str[i - 1] == '\0' && str[i - 2] == '\n'))
	{
		buf_str = ft_strsub(str, i, 21);
		i = i + 21;
		l++;
		if ((list = validate_sub(buf_str, l)) == NULL)
			return (NULL);
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
		ft_putendl("error");
		return (0);
	}
	if ((list = validate_main(str, ft_strlen(str) + 1)) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	tetri_absolute(&list);
	a = min_edge(list);
	map = create_map(list, a);
	print_map(map);
	free_map(map);
	tetri_del(&list);
}
