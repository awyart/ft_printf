/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:59:09 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:15:04 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_down((ULL)va_arg(ap, unsigned long), 16);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_down(va_arg(ap, ULL), 16);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_down((ULL)
			(unsigned short)va_arg(ap, unsigned int), 16);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_down((ULL)
			(unsigned char)va_arg(ap, unsigned int), 16);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll_down((ULL)va_arg(ap, uintmax_t), 16);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll_down((ULL)va_arg(ap, size_t), 16);
	else
		flag->content = ft_itoab_ll_down((ULL)va_arg(ap, unsigned int), 16);
	flag->len += ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_x_maj(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 16);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(
			(ULL)va_arg(ap, ULL), 16);
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
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_c(t_flag *flag, va_list ap)
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
		flag->final_len += POPS(flag->width - 1);
	}
	ft_putchar((char)va_arg(ap, int));
	flag->final_len++;
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - 1, ' ');
		flag->final_len += POPS(flag->width - 1);
	}
}

void	ft_c_maj(t_flag *flag, va_list ap)
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
		ft_putnchar_unicode(flag->width - 1, ' ');
		flag->final_len += POPS(flag->width - 1);
	}
	ft_putchar_unicode((char)va_arg(ap, int));
	flag->final_len++;
	if (flag->flags['-'])
	{
		ft_putnchar_unicode(flag->width - 1, ' ');
		flag->final_len += POPS(flag->width - 1);
	}
}
