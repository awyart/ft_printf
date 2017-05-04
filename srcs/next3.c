/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:59:09 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 20:55:54 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, unsigned long), 16);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_s(va_arg(ap, unsigned long long), 16);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, unsigned int), 16);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, unsigned int), 16);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, intmax_t), 16);
	else
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, unsigned int), 16);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_x_maj(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned long), 16);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(
			(long long)va_arg(ap, unsigned long long), 16);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 16);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 16);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, intmax_t), 16);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 16);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_c(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->width == -2147483648)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (!(flag->flags['-']))
		ft_putnchar(flag->width - 1, ' ');
	ft_putchar((char)va_arg(ap, int));
	if (flag->flags['-'])
		ft_putnchar(flag->width - 1, ' ');
}

void	ft_c_maj(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (!(flag->flags['-']))
		ft_putnchar_unicode(flag->width - 1, ' ');
	ft_putchar_unicode((char)va_arg(ap, int));
	if (flag->flags['-'])
		ft_putnchar_unicode(flag->width - 1, ' ');
}
