/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:05:29 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 14:25:22 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_b(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	if (flag->flags['l'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, long), 2);
	else if (flag->flags['l'] == 2)
		flag->content = ft_itoab_ll_s(va_arg(ap, long long), 2);
	else if (flag->flags['h'] == 1)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	else if (flag->flags['h'] == 2)
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	else
		flag->content = ft_itoab_ll_s((long long)va_arg(ap, int), 2);
	flag->len = ft_strlen(flag->content);
	put_d(flag);
}

void	ft_per(t_flag *flag, va_list ap, int *test_error)
{
	if (test_error == 0)
		test_error = 0;
	(void)ap;
	if (flag->width == -2147483648)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (!(flag->flags['-']))
		ft_putnchar(flag->width - 1, ' ');
	ft_putchar('%');
	if (flag->flags['-'])
		ft_putnchar(flag->width - 1, ' ');
}