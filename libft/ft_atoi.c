/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:53:25 by bcharity          #+#    #+#             */
/*   Updated: 2019/04/29 13:34:36 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_valid(const char *str, int n)
{
	int i;

	i = 0;
	while (*str >= 48 && *str <= 57)
	{
		i++;
		str++;
	}
	if (i > 18 && n == 1)
		return (-1);
	if (i > 18 && n == -1)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int				n;
	long long int	val;

	val = 0;
	n = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	if (check_valid(str, n) <= 0)
		return (check_valid(str, n));
	while (*str >= 48 && *str <= 57)
	{
		val = 10 * val + (*str - 48);
		str++;
	}
	return (n * (int)val);
}
