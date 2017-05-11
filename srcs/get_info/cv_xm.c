/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_xm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:20:11 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:24:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_xm(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 16);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 16);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)
			(unsigned short)va_arg(ap, unsigned int), 16);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)
			(unsigned char)va_arg(ap, unsigned int), 16);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, uintmax_t), 16);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 16);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned int), 16);
	flag->len = ft_strlen(flag->content);
}
