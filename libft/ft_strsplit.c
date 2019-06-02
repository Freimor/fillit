/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:39:56 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 16:11:10 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nextword(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static	char	**ft_strsplit_main(int i, int count, char const *s, char c)
{
	char	**split;
	int		buf;
	int		j;

	if (!(split = (char **)malloc(count * sizeof(char *))))
		return (NULL);
	while (++i < (count - 1))
	{
		j = -1;
		s = nextword(s, c);
		buf = ft_wordlen(s, c);
		if (!(split[i] = ft_strnew(buf)))
		{
			ft_str2del(&split);
			return (NULL);
		}
		while (++j < buf)
		{
			split[i][j] = *s;
			s++;
		}
		split[i][j] = '\0';
	}
	split[i] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	count = ft_countwords_withnullstr(s, c);
	return (ft_strsplit_main(i, count, s, c));
}
