/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/15 18:12:48 by sskinner         ###   ########.fr       */
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
    while (!(str[i] == '\0' && str[i - 1] == '\n') &&
    !(str[i] == '\n' && str[i - 1] == '\n'))
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
        i++;
    }
    return (k == 4) ? (1) : (-1);
}

static  int getvid(int *stack, int i)
{
    int flag;
    int vis[8];
    int k;

    flag = 0;
    k = 0; //чекает с самого себя
    vis[0] = stack[2 * i] + 1;
    vis[1] = stack[2 * i + 1] + 1;
    vis[2] = stack[2 * i] + 1;
    vis[3] = stack[2 * i + 1] - 1;
    vis[4] = stack[2 * i] - 1;
    vis[5] = stack[2 * i + 1] + 1;
    vis[6] = stack[2 * i] - 1;
    vis[7] = stack[2 * i + 1] - 1;

    while (k < 4)
    {
        if ((vis[0] == stack[2*k]) && (vis[1] == stack[2*(i + 1)]))
            flag++;
        if ((vis[2] == stack[2*k]) && (vis[3] == stack[2*(i + 1)]))
            flag++;
        if ((vis[4] == stack[2*k]) && (vis[5] == stack[2*(i + 1)]))
            flag++;
        if ((vis[6] == stack[2*k]) && (vis[7] == stack[2*(i + 1)]))
            flag++;
        k++;
    }
    printf("%d - flag\n", flag);
    return (flag);
}

static int validate_3(int *stack)
{
    int i;
    int k;
    int j;

    i = 0;
    k = 0;
    j = 0;
    while (j < 4)
    {
        printf("%d - x\n", stack[j*2]);
        printf("%d - y\n", stack[j*2 + 1]);
        j++;
    }
    while (i < 4)
    {
        k = k + getvid(stack, i);
        i++;
    }
    if (k >= 6)
        return (0);
    return (-1);
}


/*static int check(int *stack)
{
    int i;

    i = 0;
    if ((stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == 1) ||
        (stack[k] == stack[k + 2] && stack[k + 1] - stack[k + 3] == -1) ||
        (stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == 1) ||
        (stack[k + 1] == stack[k + 3] && stack[k] - stack[k + 2] == -1))
}*/

static int validate_2(char *str)
{
    int k;
    int i;
    int x;
    int y;
    int stack[8];

    k = 0;
    i = 0;
    x = -1;
    y = -1;
    while (!(str[i + 1] == '\0' && str[i] == '\n') &&
    !(str[i + 1] == '\n' && str[i] == '\n'))
    {
        y++;
        while (str[i] != '\n') //чекоть
        {
            x++;
            if (str[i] == '#') {
                stack[k] = x;
                stack[++k] = y;
                k++;
            }
            i++;
        }
        x = -1;
        i++;
    }
    if (y != 3)
        return (-1);
    return (validate_3(stack) == 0) ? (0) : (-1);
}

int     main_validate(char *str, int count) //отправлять на валидацию по 21 символу
{
    char   buf_str[21 + 1];
    int i;

    i = 0;
    if (count % 21 != 0)
        return (-1);
    while (*str != '\0')
    {
        while (i < 21)
        {
            buf_str[i] = *str;
            i++;
            str++;
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