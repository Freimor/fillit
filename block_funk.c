/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 16:44:59 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

block	*block_new(int x, int y, int index)
{
	block	*new;

	if (!(new = (block *)malloc(sizeof(block))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->index = index;
	new->next = NULL;
	return (new);
}

int		block_del(block **base, int index)
{
	block	*ptr;
	block	*buf;

	ptr = *base;
	if (*base && (*base)->index != index)
	{
		while (ptr && ptr->next->index != index)
			ptr = ptr->next;
		if (ptr)
		{
			buf = ptr->next;
			ptr->next = ptr->next->next;
			free(buf);
		}
		return (ptr) ? (0) : (-1);
	}
	else if ((*base)->index == index)
	{
		buf = *base;
		*base = (*base)->next;
		free(buf);
	}
	return (*base) ? (0) : (-1);
}

void	block_add(block **base, block *new)
{
	if (!(new))
		return ;
	new->next = *base;
	*base = new;
}

block	*block_check(block **base, int index)
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
}