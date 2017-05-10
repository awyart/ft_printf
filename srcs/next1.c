/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:52:03 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:37:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s(t_flag *flag, va_list ap)
{
	flag->content = va_arg(ap, char *);
	flag->len = ft_strlen(flag->content);
	put_s(flag);
}

void	ft_s_maj(t_flag *flag, va_list ap)
{
	flag->content = va_arg(ap, char *);
	put_s_unicode(flag);
}

void	ft_p(t_flag *flag, va_list ap)
{
	flag->content = ft_itoab_ll_down((ULL)va_arg(ap, void *), 16);
	flag->len = ft_strlen(flag->content);
	ft_putstr("0x");
	flag->final_len += 2;
	put_s(flag);
}

void	ft_d(t_flag *flag, va_list ap)
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

void	ft_d_maj(t_flag *flag, va_list ap)
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
