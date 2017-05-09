/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:04:53 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 17:12:18 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_form(t_flag *flag)
{
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->precision >= 0)
		flag->flags['0'] = 0;
	if (flag->precision != 0)
	{
		if (flag->precision >= 0 && flag->precision < flag->len)
			flag->len = flag->precision;
	}
}

void		put_s_unicode(t_flag *flag)
{
	int i;
	int pstr;

	pstr = 0;
	ft_form(flag);
	if (!(flag->flags['-']))
	{
		ft_putnchar_unicode(flag->width - flag->len, ' ');
		flag->final_len += POPS(flag->width - flag->len);
	}
	i = -1;
	while (++i < flag->len)
	{
		ft_putchar_unicode(flag->content[pstr++]);
		flag->final_len++;
	}
	if ((flag->flags['-']))
	{
		ft_putnchar_unicode(flag->width - flag->len, ' ');
		flag->final_len += POPS(flag->width - flag->len);
	}
}
