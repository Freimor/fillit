/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:18 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		validate_1(char *str)
{
	int k;

	k = 0;
	while (!(*str == '\0' && *(str - 1) == '\n')
	&& !(*str == '\n' && *(str - 1) == '\n'))
	{
		if (*str == '.' || *str == '\n')
			str++;
		if (*(str) == '#')
		{
			k++;
			str++;
		}
		if (*str != '.' && *str != '\n' && *str != '#' && *str != '\0')
			return (-1);
	}
	return (k == 4) ? (1) : (-1);
}

int		validate_2(char *str)
{
	int y;
	int x;

	y = 0;
	while (!(*str == '\0' && *(str - 1) == '\n')
	&& !(*str == '\n' && *(str - 1) == '\n'))
	{
		x = 0;
		while (*str != '\n')
		{
			x++;
			str++;
		}
		if (x != 4)
			return (-1);
		y++;
		str++;
	}
	return (y == 4) ? (1) : (-1);
}

t_fig	*validate_4(int *st, int l)
{
	int				i;
	int				k;
	static t_fig	*head;

	i = 0;
	k = 0;
	if (l == 1)
		head = tetri_new();
	while (i < 4)
	{
		k = k + getvid(st, i);
		i++;
	}
	if (k >= 6)
		return (create_list(st, &head, l));
	return (NULL);
}

t_fig	*validate_3(char *str, int l)
{
	int	k;
	int	arr[2];
	int	stack[8];

	k = 0;
	arr[1] = 0;
	while (!(*str == '\0' && *(str - 1) == '\n') &&
	!(*str == '\n' && *(str - 1) == '\n'))
	{
		arr[0] = 0;
		while (*str != '\n')
		{
			if (*str == '#')
			{
				stack[k] = arr[0];
				stack[k++ + 4] = arr[1];
			}
			arr[0]++;
			str++;
		}
		arr[1]++;
		str++;
	}
	return (validate_4(stack, l));
}

t_fig	*validate_sub(char *buf, int l)
{
	t_fig	*list;

	if (validate_1(buf) == -1)
		return (NULL);
	if (validate_2(buf) == -1)
		return (NULL);
	if ((list = validate_3(buf, l)) == NULL)
		return (NULL);
	return (list);
}
