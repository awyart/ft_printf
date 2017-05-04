/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_unicode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:43:23 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 14:02:23 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnchar_unicode(int n, char c)
{
	int x;

	x = n;
	while (x > 0)
	{
		ft_putchar_unicode((c));
		x--;
	}
}
