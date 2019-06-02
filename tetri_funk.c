/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/02 18:17:52 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetri	*tetri_new(block b1, block b2, block b3, block b4)
{
	tetri	*new;

	if (!(new = (tetri *)malloc(sizeof(tetri))))
		return (NULL);
	new->b1 = b1;
	new->b2 = b2;
	new->b3 = b3;
	new->b4 = b4;
	new->next = NULL;
	return (new);
}

int		block_del(block **base, int index)  //делой
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