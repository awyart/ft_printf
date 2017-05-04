/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:06:04 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 17:14:03 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_begin(t_flag *flag, int *sign, int *pstr)
{
	*pstr = 0;
	if (flag->width == -2147483648)
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

static void	ft_manage_sign(t_flag *flag, int n, int sign)
{
	if (flag->flags['-'])
	{
		if (sign)
			ft_putchar(sign);
	}
	else if (flag->flags['0'])
	{
		if (sign)
			ft_putchar(sign);
		ft_putnchar(flag->width - n, '0');
	}
	else
	{
		ft_putnchar(flag->width - n, ' ');
		if (sign)
			ft_putchar(sign);
	}
}

void		put_d(t_flag *flag)
{
	int sign;
	int i;
	int pstr;
	int n;
	
	ft_begin(flag, &sign, &pstr);
	ft_form_str(flag, &n, sign, pstr);
	ft_manage_sign(flag, n, sign);
	ft_putnchar(flag->precision - flag->len, '0');
	i = -1;
	while (++i < flag->len)
		ft_putchar(flag->content[pstr++]);
	if (flag->flags['-'])
		ft_putnchar(flag->width - n, ' ');
}
