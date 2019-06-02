/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:54:25 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 16:06:19 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			flag;

	flag = 0;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			ptr = s;
			flag = 1;
		}
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
	{
		ptr = s;
		flag = 1;
	}
	return (flag != 0) ? ((char *)ptr) : (NULL);
}
