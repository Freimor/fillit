/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:01:44 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 16:13:37 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hay;
	const char	*need;

	need = needle;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		hay = haystack;
		while (*haystack == *needle)
		{
			needle++;
			haystack++;
			if (*needle == '\0')
				return ((char *)hay);
			if (*haystack != *needle)
			{
				haystack = hay;
				break ;
			}
		}
		needle = need;
		haystack++;
	}
	return (NULL);
}
