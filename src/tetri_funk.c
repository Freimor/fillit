/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:14 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_fig		*tetri_new(void)
{
	t_fig	*new;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
		return (NULL);
	if (!(new->x_arr = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	if (!(new->y_arr = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	new->index = -1;
	new->next = NULL;
	return (new);
}

void		tetri_del(t_fig **base)
{
	t_fig	*ptr;

	while ((*base) != NULL)
	{
		ptr = (*base);
		*base = (*base)->next;
		free(ptr->x_arr);
		free(ptr->y_arr);
		free(ptr);
	}
}

static int	find_min(t_fig *head, int bool)
{
	int		dim;
	int		i;
	int		*arr;

	i = 0;
	arr = NULL;
	if (bool == 0)
		arr = head->x_arr;
	else if (bool == 1)
		arr = head->y_arr;
	dim = arr[0];
	while (i < 3)
	{
		if (arr[i] < dim)
			dim = arr[i];
		i++;
	}
	return (dim);
}

void		tetri_absolute(t_fig **base)
{
	int		d_x;
	int		d_y;
	t_fig	*ptr;
	int		i;

	ptr = *base;
	while (ptr != NULL)
	{
		i = 0;
		d_x = find_min(ptr, 0);
		d_y = find_min(ptr, 1);
		while (i < 4)
		{
			ptr->x_arr[i] = ptr->x_arr[i] - d_x;
			ptr->y_arr[i] = ptr->y_arr[i] - d_y;
			i++;
		}
		ptr = ptr->next;
	}
}
