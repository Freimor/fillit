/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:11:55 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 15:28:33 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	char	*fs12;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(s12 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	fs12 = s12;
	while (*s1 != '\0')
	{
		*s12 = *s1;
		s1++;
		s12++;
	}
	while (*s2 != '\0')
	{
		*s12 = *s2;
		s2++;
		s12++;
	}
	*s12 = '\0';
	return (fs12);
}
