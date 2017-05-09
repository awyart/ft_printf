/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:04:53 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 19:58:23 by awyart           ###   ########.fr       */
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

void		put_s(t_flag *flag)
{
	int i;
	int pstr;

	pstr = 0;
	ft_form(flag);
	if (flag->content == NULL && (flag->final_len += 6))
		ft_putstr("(null)");
	if (!(flag->flags['-'])
		&& (flag->final_len += POPS(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
	i = -1;
	while (++i < flag->len && (flag->final_len += 1))
		ft_putchar(flag->content[pstr++]);
	if ((flag->flags['-'])
		&& (flag->final_len += POPS(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
}
