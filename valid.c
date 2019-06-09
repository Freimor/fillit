/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 16:22:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int validate_1(char *str, int count)
{
    int i;
    int k;

    k = 0;
    while (k != 4)
    {
        while (str[i] != '\n')
        {
            if (*str != '.' && *str != '#')
                if (*str != '\n' && i % 5 == 0)
                    return (-1);
        }
    }
}

static int validate(char *str)
{
    int	i;
    int	j;
    int	k;
    int	stack[8]; //1 tetri = 8 coordinates

    i = 0;
    j = 0;
    k = 0;
    while (*str != '\0')
    {
        if (i > 20) //??
            return (-1);
        while (*str != '\n')
        {
            if (*str != '.' && *str != '#')
                if (*str != '\n' && i % 5 == 0)
                    return (-1);
                else if (*str == '#')
                {
                    stack[k] = i;
                    stack[k++] = j;
                    k++;
                }
            str++;
            j++;
        }
        if (j != 4)
            return (-1);
        j = 0;
        i = i + 4;
    }
    k = 0;
    while (k < 6) //??
    {
        if ((stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == 1) ||
            (stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == -1) ||
            (stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == 1) ||
            (stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == -1))
            k = k + 2;
        else
            return (-1);
    }
    return (0);
}

int     main_validate(char *str, int count)
{
    char   *buf_str;
    char   *tmp;

    if (count % 21 != 0)
        return (-1);
    while (ft_strlen(str) < 21)
    {
        buf_str = ft_strcopyuntil(str, str + 21);
        str = str + 21;
        if (validate_1(buf_str, count) == -1)
            return (-1);
    }
}