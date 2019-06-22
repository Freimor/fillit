/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/22 14:32:25 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void tetri_build(t_fig **head,t_fig **tetri, int i, int x, int y)
{
    if (*tetri == NULL)
    {
        *tetri = tetri_new();
    }
    (*tetri)->x_arr[i] = x;
    (*tetri)->y_arr[i] = y;
    if (i == 3)
        tetri_add_w_copy(head, tetri);
}


t_fig   *detect_and_createtetri(char *str)
{
    int		x;
    int		y;
    int		i;
    t_fig   *head;
    t_fig	*tetri;

    i = 0;
    y = 0;
    head = NULL;
    tetri = NULL;
    while (*str != '\n' && *(str + 1) != '\0')
    {
        x = 0;
        while (*str != '\n')
        {
            if (*str == '#')
            {
                tetri_build(&head, &tetri, i, x, y);
                i++;
            }
            str++;
            x++;
        }
      /* if (*str == '\n' && *(str + 1) == '\n')
        {
            tetri_add_w_copy(&head, tetri);
            str++;
        }*/
        y++;
        str++;
    }
    return (head);
}

char	*reading(int fd)
{
	int		count;
	char	str[546];
	char    *tmp;

	while ((count = read(fd, str, 546)) >= 20)
    {
        str[count] = '\0';
        tmp = strcut(str);
	}
    return (tmp);
}

