/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:57:57 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:30:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_put_size(unsigned long long value, int base)
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

char		*ft_itoab_ll(unsigned long long value, int base)
{
	int			size;
	char		*str;

	size = ft_put_size(value, base);
	str = ft_strnew(size);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789ABCDEF"[value % base];
		value = value / base;
	}
	return (str);
}
