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

static int validate_1(char *str)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while ((str[i] != '\0' && str[i - 1] == '\n') ||
    (str[i] != '\n' && str[i - 1] == '\n'))
    {
        k++;
        while (str[i] != '\n')
        {
            if (*str != '.' && *str != '#')
            {
                if (*str != '\n' && i % 5 == 0)
                    return (-1);
            }
            i++;
        }
    }
    return (k == 4) ? (1) : (-1);
}

static int validate_3(int *stack)
{
    int k;

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

static int validate_2(char *str)
{
    int k;
    int i;
    int x;
    int y;
    int stack[8];

    k = 0;
    i = 0;
    x = 0;
    y = 0;
    while ((str[i] != '\0' && str[i - 1] == '\n') ||
    (str[i] != '\n' && str[i - 1] == '\n')) {
        while (*str != '\n') //чекоть
        {
            if (str[i] == '#') {
                stack[k] = x;
                stack[k++] = y;
                k++;
            }
            i++;
            y++;
        }
        if (y != 4)
            return (-1);
        y = 0;
        x = x + 4;
    }
    return (validate_3(stack) == 0) ? (0) : (-1);
}

int     main_validate(char *str, int count) //отправлять на валидацию по 21 символу
{
    char   buf_str[21 + 1];
    int i;

    i = 0;
    if (count % 21 != 0)
        return (-1);
    while (*str == '\0')
    {
        while (i != 21)
        {
            buf_str[i] = *str;
            i++;
        }
        buf_str[i] = '\0';
        i = 0;
        if (validate_1(buf_str) == -1)
            return (-1);
        if (validate_2(buf_str) == -1)
            return (-1);
    }
    return (0);
}