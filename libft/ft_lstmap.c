/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:28:14 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 13:38:10 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(t_list *alst)
{
	t_list	*ptr;

	while (alst)
	{
		ptr = alst->next;
		ft_memdel((void **)alst->content);
		ft_memdel((void **)alst);
		alst = ptr;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	if (!(lst) || !(f))
		return (NULL);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = (*f)(lst);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
		{
			clean(new);
			return (NULL);
		}
		new->next = (*f)(lst);
		new = new->next;
	}
	return (first);
}
