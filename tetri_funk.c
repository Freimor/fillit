/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/09 15:22:22 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetri	*tetri_new()
{
	tetri	*new;

	if (!(new = (tetri *)malloc(sizeof(tetri))))
	    return (NULL);
	if (!(new->x = (int *)malloc(sizeof(int) * 4)))
	    return (NULL);
	if (!(new->y = (int *)malloc(sizeof(int) * 4)))
	    return (NULL);
	new->next = NULL;
	return (new);
}

int		tetri_del(tetri **base, tetri *del)  //делой
{
	tetri	*ptr;
	tetri	*buf;

	ptr = *base;
	if (*base && *base != del)
	{
		while (ptr && ptr->next != del)
			ptr = ptr->next;
		if (ptr)
		{
			buf = ptr->next;
			ptr->next = ptr->next->next;
			free(buf);
		}
		return (ptr) ? (0) : (-1);
	}
	else if (*base == del)
	{
		buf = *base;
		*base = (*base)->next;
		free(buf);
	}
	return (*base) ? (0) : (-1);
}

void	tetri_add(tetri **base, tetri *new)
{
	if (!(new))
		return ;
	new->next = *base;
	*base = new;
}

void	tetri_add_w_copy(tetri **base, tetri *new)
{
	tetri	*copy;

	if (!(new))
		return ;
	copy = tetri_new();
	*copy->x = *new->x;
	*copy->y = *new->y;
	copy->next = *base;
	*base = copy;
	free(new);
}

/*tetri	*tetri_check(tetri **base, int index)
{
	block	*ptr;

	ptr = *base;
	while (ptr)
	{
		if (ptr->index == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}*/