/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:07:55 by sskinner          #+#    #+#             */
/*   Updated: 2019/01/23 15:07:57 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		countiforstr(int num)
{
	int count;

	count = 0;
	if ((num < -2147483648) || (num > 2147483647))
		return (0);
	if (num == 0)
		count++;
	if (num == -2147483648)
	{
		count++;
		num /= 10;
	}
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num >= 1)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static	char	*chartostr(char *a, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(len);
	while (a[i])
	{
		str[i] = a[i];
		i++;
	}
	return (str);
}

static	char	*writestrnorm(char *str, int num, int flag)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		str[i] = "0123456789"[num % 10];
		num /= 10;
		i++;
	}
	if (flag == 1)
		str[i] = '-';
	return (str);
}

char			*ft_itoa(int num)
{
	char	*str;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	if (!(str = ft_strnew(countiforstr(num))))
		return (NULL);
	if (num == 0)
		str[i] = '0';
	if (num == -2147483648)
		return (chartostr("-2147483648", countiforstr(-2147483648)));
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	str = writestrnorm(str, num, flag);
	return (ft_strreverse(str));
}
