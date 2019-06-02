/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:44:38 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 19:08:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*news;
	size_t	i;

	i = 0;
	if (!(f) && !s)
		return (NULL);
	if (!(news = ft_strdup(s)))
		return (NULL);
	while (news[i] != '\0')
	{
		news[i] = (*f)(s[i]);
		i++;
	}
	return (news);
}
