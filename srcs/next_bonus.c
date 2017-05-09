/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:05:29 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 19:41:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_b(t_flag *flag, va_list ap)
{
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, long), 2);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_s(va_arg(ap, long long), 2);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	else if (flag->flags['j'] == 1)
		flag->content = ft_itoab_ll((long long)va_arg(ap, intmax_t), 2);
	else if (flag->flags['z'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, size_t), 2);
	else
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_per(t_flag *flag, va_list ap)
{
	(void)ap;
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
	ft_putchar('%');
	flag->final_len++;
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - 1, ' ');
		flag->final_len += POPS(flag->width - 1);
	}
}
