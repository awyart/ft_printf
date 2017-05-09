/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:52:03 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 19:45:08 by awyart           ###   ########.fr       */
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
	flag->content = (char*)va_arg(ap, void*);
}

void	ft_d(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_s(va_arg(ap, long long), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, intmax_t), 10);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, size_t), 10);
	else
	{
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	}
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}

void	ft_d_maj(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, long), 10);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_s(va_arg(ap, long long), 10);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, intmax_t), 10);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, size_t), 10);
	else
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 10);
	flag->len = ft_strlen(flag->content);
	if (flag->content[0] == '0' && flag->len == 1)
		flag->len = 0;
	put_d(flag);
}
