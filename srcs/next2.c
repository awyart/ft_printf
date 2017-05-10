/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:02:58 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 18:40:51 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_i(t_flag *flag, va_list ap)
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
		flag->content = ft_itoa((LL)va_arg(ap, int));
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_o(t_flag *flag, va_list ap)
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
	if (flag->flags['#'] >= 1)
		flag->content = ft_strjoin("0", flag->content);
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == (1 + flag->flags['#']))
		flag->len = flag->flags['#'];
	put_d(flag);
}

void	ft_o_maj(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 8);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 8);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 8);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)
			(unsigned short)va_arg(ap, unsigned int), 8);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, uintmax_t), 8);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 8);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 8);
	if (flag->flags['#'] >= 1)
		flag->content = ft_strjoin("0", flag->content);
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_u(t_flag *flag, va_list ap)
{
	flag->flags['+'] = 0;
	flag->flags[' '] = 0;
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
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned int), 10);
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_u_maj(t_flag *flag, va_list ap)
{
	flag->flags['+'] = 0;
	flag->flags[' '] = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll(va_arg(ap, ULL), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll((ULL)
			(unsigned short)va_arg(ap, unsigned int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, uintmax_t), 10);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll((ULL)va_arg(ap, size_t), 10);
	else
		flag->content = ft_itoab_ll((ULL)va_arg(ap, unsigned long), 10);
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}
