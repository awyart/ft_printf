/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:49:06 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:39:49 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_put_long(long long *value)
{
	if (*value < 0)
	{
		*value = -(*value);
		return (1);
	}
	return (0);
}

static int	ft_put_size(long long value)
{
	int size;

	size = 0;
	if (value == 0)
		size = 1;
	else
		while (value != 0)
		{
			value = value / 10;
			size++;
		}
	return (size);
}

static char	*ft_handle_llmax(long long value, int size)
{
	char *str;

	str = ft_strnew(size);
	str[size + 1] = '\0';
	str[size] = "0123456789"[-(value % 10)];
	value = value / 10;
	value = -value;
	while (--size >= 0)
	{
		str[size] = "0123456789"[value % 10];
		value /= 10;
	}
	str[0] = '-';
	return (str);
}

char		*ft_itoa(long long value)
{
	int			neg;
	int			size;
	char		*str;

	size = ft_put_size(value);
	if (value == LLONG_MIN)
	{
		str = ft_handle_llmax(value, size);
		return (str);
	}
	neg = ft_put_long(&value);
	size = size + neg;
	str = ft_strnew(size);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789"[value % 10];
		value = value / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
