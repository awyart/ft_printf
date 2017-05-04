/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:02:58 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 20:56:52 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_i(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, long long), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, intmax_t), 10);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, int), 10);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_o(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned long), 8);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, unsigned long long), 8);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, uintmax_t), 8);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_o_maj(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned long), 8);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(
			(long long)va_arg(ap, unsigned long long), 8);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, uintmax_t), 8);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 8);
	flag->len = ft_strlen(flag->content);
	put_d_unicode(flag);
}

void	ft_u(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(
			(long long)va_arg(ap, unsigned long long), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, uintmax_t), 10);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_u_maj(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(
			(long long)va_arg(ap, unsigned long long), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, uintmax_t), 10);
	else
		flag->content = ft_itoab_ll((long long)va_arg(ap, unsigned int), 10);
	flag->len = ft_strlen(flag->content);
	put_d_unicode(flag);
}
