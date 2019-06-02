/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:08:38 by sskinner          #+#    #+#             */
/*   Updated: 2019/05/18 18:18:42 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check(const char *haystack, const char *needle, size_t len)
{
	while (*haystack)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		len--;
	}
	return (len == 0) ? (1) : (0);
}

static char	*ft_strnd(const char *s1, const char *s2, size_t n, size_t i)
{
	size_t	j;

	j = 0;
	while (s1[i] && n > 0)
	{
		if (s1[i] == s2[j])
		{
			if (ft_strlen(s2) == 1)
				return ((char *)&s1[i - ft_strlen(s2) + 1]);
			j++;
			if ((j == ft_strlen(s2) - 1) &&
			(s1[i + 1] == s2[j]) && (n - 1) > 0)
				return ((char *)&s1[i - ft_strlen(s2) + 2]);
			if (s1[i + 1] != s2[j])
			{
				i = i - j + 1;
				n = n + j - 1;
				j = 0;
			}
		}
		i++;
		n--;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if ((needle[0] == '\0') || (check(haystack, needle, len) == 1))
		return ((char *)haystack);
	return (ft_strnd(haystack, needle, len, i));
}
