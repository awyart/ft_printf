/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:34:30 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 17:40:52 by awyart           ###   ########.fr       */
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

static int	ft_manage_diese(t_flag *flag)
{
	if (flag->flag_type == 'x' || flag->flag_type == 'X')
		if (flag->flags['#'] >= 1
		&& !(ft_strlen(flag->content) > 0 && flag->content[0] == '0'))
			return (1);
	return (0);
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
	char str[2];

	str[0] = '0';
	str[1] = flag->flag_type;
	if (ft_manage_diese(flag))
		flag->width -= 2;
	if (flag->flags['-'] || flag->flags['0'])
	{
		if (ft_manage_diese(flag) && (flag->final_len += 2))
			ft_putstr_unicode(str);
		if (sign && (flag->final_len += 1))
			ft_putchar_unicode(sign);
		if (!(flag->flags['-']) && (flag->final_len += POPS(flag->width - n)))
			ft_putnchar_unicode(flag->width - n, '0');
	}
	else
	{
		ft_putnchar_unicode(flag->width - n, ' ');
		flag->final_len += POPS(flag->width - n);
		if (ft_manage_diese(flag) && (flag->final_len += 2))
			ft_putstr_unicode(str);
		if (sign && (flag->final_len += 1))
			ft_putchar_unicode(sign);
	}
}

void		put_d_unicode(t_flag *flag)
{
	int sign;
	int i;
	int pstr;
	int n;

	ft_begin(flag, &sign, &pstr);
	ft_form_str(flag, &n, sign, pstr);
	ft_manage_sign(flag, n, sign);
	ft_putnchar_unicode(flag->precision - flag->len, '0');
	flag->final_len += POPS(flag->precision - flag->len);
	i = -1;
	while (++i < flag->len)
	{
		ft_putchar_unicode(flag->content[pstr++]);
		flag->final_len++;
	}
	if (flag->flags['-'])
	{
		ft_putnchar_unicode(flag->width - n, ' ');
		flag->final_len += POPS(flag->width - n);
	}
}
