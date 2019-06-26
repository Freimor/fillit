/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_funk_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/26 19:36:12 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_fig	*create_list(int *st, t_fig **head, int l)
{
	int				i;
	int				j;
	static t_fig	*list;

	i = 0;
	list = new_list(head, l);
	while (i < 4)
	{
		list->x_arr[i] = st[i];
		list->y_arr[i] = st[i + 4];
		i++;
	}
	return (*head);
}

t_fig	*new_list(t_fig **head, int l)
{
	t_fig	*tmp;
	t_fig	*new;
	int		i;

	i = 0;
	tmp = *head;
	if (l == 1)
	{
		(*head)->index = 0;
		return (*head);
	}
	new = tetri_new();
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->index = l - 1;
	tmp->next = new;
	return (new);
}

char	*reading(int ac, char *av)
{
	char	str[546];
	char	*tmp;
	int		count;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage [map]");
		return (NULL);
	}
	tmp = NULL;
	fd = open(av, O_RDONLY);
	count = read(fd, str, 546);
	str[count] = '\0';
	tmp = ft_strndup(str, count);
	if ((count = read(fd, str, 546)) > 0)
		return (NULL);
	close(fd);
	return (tmp);
}
