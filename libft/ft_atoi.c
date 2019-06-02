/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:10:53 by sskinner          #+#    #+#             */
/*   Updated: 2019/04/17 18:22:38 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					flag;
	size_t				i;
	long int			s;
	long int			temp;

	flag = 1;
	i = 0;
	s = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		flag = str[i++] == '-' ? (-1) : (1);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		temp = s;
		s *= 10;
		s += str[i] - '0';
		if (temp > s)
			return (flag == 1) ? (-1) : (0);
		i++;
	}
	return (flag * s);
}
