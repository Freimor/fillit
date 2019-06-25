/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 14:17:55 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


t_fig   *create_list(int *st, t_fig **head, int l)
{
    int		i;
    int     j;
    static  t_fig   *list;

    i = 0;
    list = new_list(head,l);
    while(i < 4)
    {
        list->x_arr[i] = st[i];
        printf("list.x_%d\n",list->x_arr[i]);
        list->y_arr[i] = st[i + 4];
        printf("list.y_%d\n",list->y_arr[i]);
        i++;
    }
    return (*head);
}


t_fig			*new_list(t_fig **head, int l)
{
    t_fig	*tmp;
    t_fig	*new;
    int     i;

    i = 0;
    tmp = *head;
    if (l == 1)
    {
        (*head)->index = 0;
        return (*head);
    }
    new = tetri_new();
    while (tmp->next != NULL)
   {
      /*  printf("tmp->index= %d\n",tmp->index);
        for(int j = 0; j < 4; j++)
        {
            printf("*tmp->x[%d]_%d\n",j,tmp->x_arr[j]);
            printf("*tmp->y[%d]_%d\n",j,tmp->y_arr[j]);

        }*/
       tmp = tmp->next;
     /*  printf("**tmp->index= %d\n",tmp->index);
       for(int j = 0; j < 4; j++)
       {
           printf("**tmp->x[%d]_%d\n",j,tmp->x_arr[j]);
           printf("**tmp->y[%d]_%d\n",j,tmp->y_arr[j]);

       }*/
    }
   // printf("tmp->index2= %d\n",tmp->index);

    new->index = l - 1;
    tmp->next = new;
   /* printf("***tmp->index= %d\n",new->index);
    for(int j = 0; j < 4; j++)
    {
        printf("***tmp->x[%d]_%d\n",j, new->x_arr[j]);
        printf("***tmp->y[%d]_%d\n",j,new->y_arr[j]);

    }*/
    return (new);
}

char	*reading(int fd)
{
	char	str[546];
	char    *tmp;
    int     count;

	tmp = NULL;
	while ((count =read(fd, str, 546)) >= 20)
	{
	    str[count] = '\0';
        tmp = strcut(str);
    }
    return (tmp);
}

