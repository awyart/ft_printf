/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab_ll_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:53:05 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:39:31 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	ft_down(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

char		*ft_itoab_ll_down(unsigned long long value, int base)
{
	char *a;

	a = ft_itoab_ll(value, base);
	ft_down(a);
	return (a);
}
