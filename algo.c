/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 17:09:20 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int check_avail(int *x,int *y, int dx,int dy, char **map)
{
    int i;
    int nx;
    int ny;
	
	i = 0;
    while(i < 4)
    {
		nx = x[i] + dx;
        ny = y[i] + dy;
        printf("nx = %d___ny = %d\n", nx,ny);
        printf("map= %c\n",map[ny][nx]);
        if(map[ny][nx] == '.')
        {
//			printf("check_%c\n",map[ny][nx]);
            i++;
        }
		else
			return(0);
    }
        return (1);
}

void	to_map(t_fig *list, int dx, int dy, char **map)
{
    int		*x;
    int		*y;
    int		i;
    char	c;

    i = 0;
    x = list->x_arr;
    y = list->y_arr;
    c = list->index + 64;
    printf("c_%c\n", c);
    while(i < 4)
    {
        map[y[i]+dy][x[i]+dx] = c;
      //  printf("to_map_c_%c\n",map[y[i]-dy-1][x[i]+dx]);
        i++;
    }
}

void	clear(t_fig *list, int dx, int dy, char **map)
{
    int *x;
    int *y;
    int i;
    char c;

    i = 0;
    x = list->x_arr;
    y = list->y_arr;
    c = list->index + 64;
    printf("c_%c\n", c);
    while(i < 4)
    {
        map[y[i]-dy-1][x[i]+dx] = '.';
        //  printf("to_map_c_%c\n",map[y[i]-dy-1][x[i]+dx]);
        i++;
    }

}

int		fill_map(int a, t_fig *list, char **map)
{
    int dx;
    int dy;
    int *x;
    int *y;

    x = list->x_arr;
    y = list->y_arr;
    dy = 0;
    while (dy < a)
    {
		dx = 0;
        while (dx < a)
        {
			if (check_avail(x,y,dx,dy,map))
            {
//				printf("DX_1=%d__DY_1=%d\n", dx,dy);
                to_map(list, dx, dy,map);
//              printf("OK\n");
                if(list->next == NULL || fill_map(a, list->next, map))
					return (1);
			}
			dx++;
		}
        dy++ ;
    }// найти место для фигуры не удалось
     if (list->index == 0)
         return (-1);// fill_map(a++, fig, map));
	return (0);
}

static int     min_edge(t_fig *list)
{
    int a;
    int n;

    n = 0;
    while(list)
    {
        n++;
        list = list->next;
    }
    printf("n = %d\n",n);
    a = 0;
    while (a * a < 4*n)
    {
        a++;
    }
    return (a);
}

char **zero_map(int a)
{
    int		i;
    int		j;
    char	**map;

   j = 0;
//	map = ft_memalloc((a+1)*sizeof(char*));
   if(!(map = (char**)malloc((a+1)*sizeof(char*))))
	   return(NULL);
   while(j < a+1)
   {
	   map[j] = ft_memalloc((a+1)*sizeof(char));
       // map[j] = (char*)malloc((a+1)*sizeof(char));
       j++;
	}
    j = 0;
    while(j < a)
    {
       /* i = 0;
        while(i < a)
        {
            map[i][j] = '.';
            i++;
        }*/
		map[j] = ft_memset(map[j], '.', a);
        map[a][j] = '\0';
        j++;
    }
    map[a] = NULL;
    return(map);
}

char *free_map(char **map)
{
    int i;

    i = ft_strlen(map[0]) ;
    while(i +1 > 0)
    {
        free(map[i]);
        i--;
    }
    free(map);
    return(NULL);
}

char**create_map (t_fig *list,int a)
{
    char **map;
    int f;
	
    map = zero_map(a);
    f = fill_map(a, list, map);
    if (f == 1)
        return (map);
    else if (f == -1)
    {
        printf("NEED_a++\n");
        free_map(map);
        return(create_map(list, a+1));
    }
    return(map);
}


void    print_map(char **map)
{
      int j;

      j = 0;
      while(map[j])
      {
          ft_putstr(map[j]);
          ft_putchar('\n');
          j++;
      }
}

int main(int ac, char **av)
{
    t_fig *list;
    char **map;
    char *str;
    int fd;
    int a;

	
	// printf("a = %d\n",a);
	if (ac != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
    str = reading(fd);
    if (main_validate(str, ft_strlen(str) + 1) == -1)
	{
		ft_putendl("error");
        return (-1);
	}
	close(fd);
    list = detect_and_createtetri(str);
	tetri_absolute(&list);
	a = min_edge(list);
    map = create_map(list,a);
	print_map(map);
    free_map(map);
    tetri_del(&list);
}
