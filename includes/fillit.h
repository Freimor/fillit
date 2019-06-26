/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:39 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_figure	t_fig;

struct		s_figure
{
	int		*x_arr;
	int		*y_arr;
	int		index;
	t_fig	*next;
};
char		**create_map (t_fig *list, int a);
char		**zero_map(int a);
int			fill_map(int a, t_fig *fig, char **map);
int			check_avail(int *x, int *y, int disp[2], char **map);
void		to_map(t_fig *list, int disp[2], char **map);
char		*free_map(char **map);
void		print_map(char **map);
char		*reading(int ac, char *av);
t_fig		*tetri_new();
t_fig		*new_list(t_fig **head, int l);
void		tetri_del(t_fig **base);
void		tetri_absolute(t_fig **head);
int			validate_1(char *str);
int			validate_2(char *str);
t_fig		*validate_4(int *st, int l);
t_fig		*validate_3(char *str, int l);
t_fig		*validate_sub(char *buf, int l);
t_fig		*validate_main(char *str, int count);
t_fig		*create_list(int *st, t_fig **head, int l);
int			func_flag(const int vis[8], int *stack);
int			getvid(int *stack, int i);
int			min_edge(t_fig *list);
#endif
