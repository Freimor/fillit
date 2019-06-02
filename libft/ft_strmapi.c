/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:57:03 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 19:08:12 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*news;
	size_t	i;
	size_t	len;

	i = 0;
	if (!(f) && !s)
		return (NULL);
	len = ft_strlen(s);
	if (!(news = ft_strndup(s, len)))
		return (NULL);
	while (news[i] != '\0')
	{
		news[i] = (*f)(i, s[i]);
		i++;
	}
	return (news);
}
