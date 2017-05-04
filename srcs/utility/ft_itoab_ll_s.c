/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab_ll_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:00:06 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 16:55:41 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_long(long long value, int base, long long *nb)
{
	if (value < 0)
	{
		*nb = -(long long)value;
		if (base == 10)
			return (1);
	}
	else
		*nb = (long long)value;
	return (0);
}

char		*ft_itoab_ll_s(long long value, int base)
{
	long long	nb;
	int			neg;
	int			size;
	char		*str;

	size = 0;
	neg = ft_put_long(value, base, &nb);
	if (value == 0)
		size = 1;
	else
		while (value != 0)
		{
			value = value / base;
			size++;
		}
	size = size + neg;
	str = ft_strnew(size);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789abcdef"[nb % base];
		nb = nb / base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
