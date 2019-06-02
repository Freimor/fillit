/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:28:21 by sskinner          #+#    #+#             */
/*   Updated: 2019/01/22 13:28:23 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjunk(int c)
{
	return (c == ' '
	|| c == '\t'
	|| c == '\n'
	|| c == ',');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (ft_strjunk(s[start]))
		start++;
	while (ft_strjunk(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	if (!(new = ft_strnew(end - start)))
		return (NULL);
	if (end == start)
		return (new);
	if (ft_strncpy(new, &(s[start]), end - start))
		new[end - start] = '\0';
	return (new);
}
