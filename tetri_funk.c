/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/22 14:32:29 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig	*tetri_new()
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

void	tetri_del(t_fig **base)  //возможно понадобится простое удаление листов
{
    t_fig *ptr;

    while ((*base) != NULL) {
        ptr = (*base);
        *base = (*base)->next;
        free(ptr->x_arr);
        free(ptr->y_arr);
        free(ptr);
    }
}

void	tetri_add_w_copy(t_fig **head, t_fig **new)
{
	t_fig	*copy;
	t_fig   *tmp;
	int i;

	i= 0;
	if (*head == NULL)
	    head = new;
    tmp = *head;
    while(tmp->next)
	    i++;
    (*new)->index = i;
	copy = tetri_new();
	copy->x_arr = (*new)->x_arr;
	copy->y_arr = (*new)->y_arr;
	copy->index = (*new)->index;
    (*head)->next = *new;

    /*
    copy->next = *base;
    *base = copy;
    (*base)->previous = copy;
    free(new);*/
}

char    *strcut(char *str)
{
    char    *buf;
    int     i;

    i = 0;
    while (str[i] != '\0')
        i++;
    buf = ft_strndup(str, i);
    return (buf);
}

void   tetri_absolute(t_fig **base)
{
    int d_x;
    int d_y;
    t_fig   *ptr;
    int i;

    i = 0;
    d_x = 0;
    d_y = 0;
    ptr = *base;
    while (ptr->next != NULL)
    {
        if (ptr->x_arr[i] < d_x)
            d_x = ptr->x_arr[i];
        if (ptr->y_arr[i] < d_y)
            d_y = ptr->y_arr[i];
        ptr = ptr->next;
    }
    ptr = *base;
    while (i != 8)
    {
        ptr->x_arr[i] = ptr->x_arr[i] - d_x;
        ptr->y_arr[i] = ptr->y_arr[i] - d_y;
        i++;
    }
}
