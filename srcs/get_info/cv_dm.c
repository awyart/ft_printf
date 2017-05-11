/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_dm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:56:03 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:06:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_dm(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoa((LL)va_arg(ap, long));
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoa(va_arg(ap, LL));
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoa((LL)(short)va_arg(ap, int));
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoa((LL)(char)va_arg(ap, int));
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoa((LL)va_arg(ap, intmax_t));
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoa((LL)va_arg(ap, size_t));
	else
		flag->content = ft_itoa((LL)va_arg(ap, long));
	flag->len = ft_strlen(flag->content);
}