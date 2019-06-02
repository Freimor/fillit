/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:10:21 by sskinner          #+#    #+#             */
/*   Updated: 2019/01/15 14:10:23 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			sizeless;
	size_t			dstsize;
	char			*dstcopy;
	const char		*srccopy;

	sizeless = size;
	dstcopy = dst;
	srccopy = src;
	while (sizeless-- != 0 && *dstcopy != '\0')
		dstcopy++;
	dstsize = dstcopy - dst;
	sizeless = size - dstsize;
	if (sizeless == 0)
		return (dstsize + ft_strlen(src));
	while (*srccopy != '\0')
	{
		if (sizeless != 1)
		{
			*dstcopy++ = *srccopy;
			sizeless--;
		}
		srccopy++;
	}
	*dstcopy = '\0';
	return (dstsize + (srccopy - src));
}
