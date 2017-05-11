/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:52:23 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 16:00:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_form(t_flag *flag)
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

void					ft_p(t_flag *flag, int *count)
{
	int i;

	ft_form(flag);
	if (flag->content == NULL && (*count += 6))
		ft_putstr("(null)");
	else
	{
		if (!(flag->flags['-']) && (*count += POPS(flag->width - flag->len)))
			ft_putnchar(flag->width - flag->len, ' ');
		i = -1;
		ft_putstr("0x");
		*count += 2;
		while (++i < flag->len && ((*count)++))
			ft_putchar(flag->content[i]);
		if ((flag->flags['-']) && (*count += POPS(flag->width - flag->len)))
			ft_putnchar(flag->width - flag->len, ' ');
}