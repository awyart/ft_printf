/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:25:50 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:29:45 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print"

void	conv_b(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, long), 2);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, LL), 2);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)(short)va_arg(ap, int), 2);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)(char)va_arg(ap, int), 2);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, intmax_t), 2);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 2);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, int), 2);
	flag->len = ft_strlen(flag->content);
}

void	conv_bm(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, long), 2);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, LL), 2);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)(short)va_arg(ap, int), 2);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)(char)va_arg(ap, int), 2);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, intmax_t), 2);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 2);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, long), 2);
	flag->len = ft_strlen(flag->content);
}