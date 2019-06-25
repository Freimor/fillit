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
    int k;

    k = 0;
    while (!(*str == '\0' && *(str - 1) == '\n') &&
    !(*str == '\n' && *(str - 1) == '\n'))
    {
        if (*str == '.' || *str == '\n')//НЕ(А+В)=НЕ(А)*НЕ(В)
            str++;
        if (*(str) == '#')
        {
            k++;
            str++;
        }
        if(*str != '.' && *str != '\n' && *str != '#' && *str != '\0' )
            return (-1);
    }
    printf("k(valid1) = %d\n ",k);
    return (k == 4) ? (1) : (-1);
}

static int     func_flag(const int vis[8],int *stack)
{
    int k;
    int flag;

    k = 0;
    flag = 0;
    while (k < 4)
    {
        if ((vis[0] == stack[k]) && (vis[1] == stack[k + 4]))
            flag++;
        if ((vis[2] == stack[k]) && (vis[3] == stack[k + 4]))
            flag++;
        if ((vis[4] == stack[k]) && (vis[5] == stack[k + 4]))
            flag++;
        if ((vis[6] == stack[k]) && (vis[7] == stack[k + 4]))
            flag++;
        k++;
    }
    return (flag);
}

static  int getvid(int *stack, int i)
{
    int flag;
    int vis[8];

    vis[0] = stack[i] + 1;  //+x
    vis[1] = stack[i + 4]; //y
    vis[2] = stack[i];  //x
    vis[3] = stack[i + 4] + 1;  //+y
    vis[4] = stack[i] - 1;  //-x
    vis[5] = stack[i + 4];  //y
    vis[6] = stack[i];  //x
    vis[7] = stack[i + 4] - 1;  //-y

    flag = func_flag(vis, stack);
    printf("flag = %d\n",flag);
    return (flag);
}

static t_fig *validate_3(int *st, int l)
{
    int     i;
    int     k;
    static  t_fig   *head;

    i = 0;
    k = 0;

    if (l == 1)
        head = tetri_new();
    while (i < 4)
    {
        k = k + getvid(st, i);
        i++;
    }
    printf("k(sum flag) = %d\n",k);
    if (k >= 6)
       return(create_list(st, &head,l));
    return (NULL);
}

static int validate_n(char *str)
{

    int y;
    int x;

    y = 0;
    while (!(*str == '\0' && *(str - 1) == '\n') &&
           !(*str == '\n' && *(str - 1) == '\n'))
    {
        x = 0;
        while (*str != '\n')
        {
            x++;
            str++;
        }
        if(x != 4)
            return(-1);
        y++;
        str++;
    }
    return (y == 4) ? (1) : (-1);

}

static t_fig *validate_2(char *str, int l)
{
    int k;
    int arr[2];
    int stack[8];

    k = 0;
    arr[1] = 0;
    while (!(*str == '\0' && *(str - 1) == '\n') &&
    !(*str == '\n' && *(str- 1) == '\n'))
    {
        arr[0] = 0;
        while (*str != '\n')
        {
            if (*str == '#')
            {
                stack[k] = arr[0];
                printf("stack_X[%d] = %d\n",k,stack[k]);
                stack[k + 4] = arr[1];
                printf("stack_Y[%d] = %d\n",k,stack[k+4]);

                k++;
            }
            arr[0]++;
            str++;
        }
        arr[1]++;
        str++;
            }
    printf("l-1 = %d\n",l-1);
    return (validate_3(stack, l));
}

t_fig     *main_validate(char *str, int count) //отправлять на валидацию по 21 символу
{
    char   buf_str[21 + 1];
    int i;
    t_fig   *list;
    int l;

    l = 0;
    list = NULL;
    if (count % 21 != 0)
        return (NULL);
    while (!(*(str - 1) == '\0' && *(str - 2) == '\n'))
    {
        i = 0;
        while (i < 21)
        {
            buf_str[i] = *str;
            i++;
            str++;
        }
        l++;
        buf_str[i] = '\0';  //buf[21]='\0'(22-ой элемент = '\0')
        if (validate_1(buf_str) == -1)
            return (NULL);
        if (validate_n(buf_str) == -1)
            return (NULL);
        if ((list = validate_2(buf_str, l)) == NULL)
            return (NULL);
    }
    return (list);
}