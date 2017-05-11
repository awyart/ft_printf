/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:42:15 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 16:05:01 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_begin(t_flag *flag, int *sign, int *pstr)
{
	*pstr = 0;
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->precision >= 0)
		flag->flags['0'] = 0;
	if (flag->len > 0 && (flag->content[*pstr] == '-'
		|| flag->content[*pstr] == '+'))
	{
		*sign = flag->content[*pstr];
		(flag->len)--;
		(*pstr)++;
	}
	else if (flag->flags['+'])
		*sign = '+';
	else if (flag->flags[' '])
		*sign = ' ';
	else
		*sign = 0;
}

static void	ft_form_str(t_flag *flag, int *n, int sign, int pstr)
{
	if (flag->precision < 0)
		flag->precision = 1;
	if (flag->len < flag->precision)
		*n = flag->precision;
	else if (flag->precision == 0 && flag->len == 1 &&
				flag->content[pstr] == '0')
		*n = 0;
	else
		*n = flag->len;
	if (sign)
		(*n)++;
}

static void	ft_manage_sign(t_flag *flag, int n, int sign, int *count)
{
	if (flag->flags['-'] || flag->flags['0'])
	{
		if (sign && (*count += 1))
			ft_putchar(sign);
		if (!(flag->flags['-']) && (*count += POPS(flag->width - n)))
			ft_putnchar(flag->width - n, '0');
	}
	else
	{
		ft_putnchar(flag->width - n, ' ');
		*count += POPS(flag->width - n);
		if (sign && (*count += 1))
			ft_putchar(sign);
	}
}

void					ft_d(t_flag *flag, int *count)
{
	int sign;
	int i;
	int pstr;
	int n;

	ft_begin(flag, &sign, &pstr);
	ft_form_str(flag, &n, sign, pstr);
	ft_manage_sign(flag, n, sign, count);
	ft_putnchar(flag->precision - flag->len, '0');
	*count += POPS(flag->precision - flag->len);
	i = -1;
	while (++i < flag->len)
	{
		ft_putchar(flag->content[pstr++]);
		(*count)++;
	}
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - n, ' ');
		*count += POPS(flag->width - n);
	}
}
