/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_cm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:43:03 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 16:26:59 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_cm(t_flag *flag, int *count)
{
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (!(flag->flags['-']))
	{
		ft_putnchar(flag->width - 1, ' ');
		*count += POPS(flag->width - 1);
	}
	ft_putchar_unicode((char)va_arg(ap, int));
	*(count)++;
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - 1, ' ');
		*count += POPS(flag->width - 1);
	}
}