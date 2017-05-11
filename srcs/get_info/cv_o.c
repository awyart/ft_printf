/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:07:25 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:08:31 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_o(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 8);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 8);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)
			(unsigned short)va_arg(ap, unsigned int), 8);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)
			(unsigned char)va_arg(ap, unsigned int), 8);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, uintmax_t), 8);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 8);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned int), 8);
	flag->len = ft_strlen(flag->content);
}