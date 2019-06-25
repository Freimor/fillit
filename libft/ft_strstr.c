/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:36:40 by bcharity          #+#    #+#             */
/*   Updated: 2019/05/01 15:55:15 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *ph;
	const char *pn;

	pn = needle;
	while (haystack)
	{
		ph = haystack;
		while (*(haystack) == *(needle) || !(*needle))
		{
			if (!(*needle))
			{
				return (char*)ph;
			}
			haystack++;
			needle++;
		}
		if (!*haystack)
			return (NULL);
		needle = pn;
		haystack = ph + 1;
	}
	return (NULL);
}
