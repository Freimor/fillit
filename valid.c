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
    vis[0] = stack[2 * i] + 1;  //+x
    vis[1] = stack[2 * i + 1]; //y
    vis[2] = stack[2 * i];  //x
    vis[3] = stack[2 * i + 1] + 1;  //+y
    vis[4] = stack[2 * i] - 1;  //-x
    vis[5] = stack[2 * i + 1];  //y
    vis[6] = stack[2 * i];  //x
    vis[7] = stack[2 * i + 1] - 1;  //-y

    printf("stack [0] %d\n", stack[0]);
    printf("stack [1] %d\n", stack[1]);
    printf("stack [2] %d\n", stack[2]);
    printf("stack [3] %d\n", stack[3]);
    printf("stack [4] %d\n", stack[4]);
    printf("stack [5] %d\n", stack[5]);
    printf("stack [6] %d\n", stack[6]);
    printf("stack [7] %d\n", stack[7]);


    printf("vis [0] %d\n", vis[0]);
    printf("vis [1] %d\n", vis[1]);
    printf("vis [2] %d\n", vis[2]);
    printf("vis [3] %d\n", vis[3]);
    printf("vis [4] %d\n", vis[4]);
    printf("vis [5] %d\n", vis[5]);
    printf("vis [6] %d\n", vis[6]);
    printf("vis [7] %d\n", vis[7]);

    while (k < 4)
    {
        if ((vis[0] == stack[2 * k]) && (vis[1] == stack[2 * k + 1]))
            flag++;
        if ((vis[2] == stack[2 * k]) && (vis[3] == stack[2 * k + 1]))
            flag++;
        if ((vis[4] == stack[2 * k]) && (vis[5] == stack[2 * k + 1]))
            flag++;
        if ((vis[6] == stack[2 * k]) && (vis[7] == stack[2 * k + 1]))
            flag++;
        k++;
    }
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
    while (i < 4)
    {
        k = k + getvid(stack, i);
        i++;
    }
    printf("%d\n", k);
    if (k >= 6)
        return (0);
    return (-1);
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
    x = -1;
    y = -1;
    while (!(str[i] == '\0' && str[i - 1] == '\n') &&
    !(str[i] == '\n' && str[i - 1] == '\n')) /////////
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
        printf("%c + 1\n", str[i + 1]);
        printf("%c\n", str[i]);
        printf("%c - 1\n", str[i - 1]);
        printf("%c - 2\n", str[i - 2]);

    }
    if (y != 3)
        return (-1);
    if (k != 8)
        return (-1);
    return (validate_3(stack) == 0) ? (0) : (-1);
}

int     main_validate(char *str, int count) //отправлять на валидацию по 21 символу
{
    char   buf_str[21 + 1];
    int i;

    i = 0;
    if (count % 21 != 0) //МЫ ЖЕ СЧИТАЛИ РОВНО 21 СИМВОЛ??
        return (-1);
    while (*str != '\0')
    {
        while (i < 21)
        {
            buf_str[i] = *str;
            i++;
            str++;
        }
        if (buf_str[i - 1] != '\0')
            buf_str[i] = '\0';
        i = 0;
        if (validate_1(buf_str) == -1)
            return (-1);
        if (validate_2(buf_str) == -1)
            return (-1);
    }
    return (0);
}