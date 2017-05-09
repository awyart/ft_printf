/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:57:57 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 16:11:38 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_put_long(long long *value, int base)
{
	if (*value < 0)
	{
		*value = -(*value);
		if (base == 10)
			return (1);
	}
	return (0);
}

static int	ft_put_size(long long value, int base)
{
	int size;

	size = 0;
	if (value == 0)
		size = 1;
	else
		while (value != 0)
		{
			value = value / base;
			size++;
		}
	return (size);
}

static char	*ft_handle_llmax(long long value, int size, int base)
{
	char *str;

	str = ft_strnew(size);
	str[size + 1] = '\0';
	str[size] = "0123456789ABCDEF"[-(value % base)];
	value = value / base;
	value = -value;
	while (--size >= 0)
	{
		str[size] = "0123456789ABCDEF"[value % base];
		value /= base;
	}
	str[0] = '-';
	return (str);
}

char		*ft_itoab_ll(long long value, int base)
{
	int			neg;
	int			size;
	char		*str;

	size = ft_put_size(value, base);
	if (value == LLONG_MIN)
	{
		str = ft_handle_llmax(value, size, base);
		return (str);
	}
	neg = ft_put_long(&value, base);
	size = size + neg;
	str = ft_strnew(size);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789ABCDEF"[value % base];
		value = value / base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
