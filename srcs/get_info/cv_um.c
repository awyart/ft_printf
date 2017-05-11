/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_um.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:09:50 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:15:06 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_um(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, ULL), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)
			(unsigned short)va_arg(ap, unsigned int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)
			(unsigned char)va_arg(ap, unsigned int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, uintmax_t), 10);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 10);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 10);
	flag->len = ft_strlen(flag->content);
}
