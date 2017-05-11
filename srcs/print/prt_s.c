/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:31:38 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 15:57:43 by awyart           ###   ########.fr       */
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

void		ft_s(t_flag *flag, int *count)
{
	int i;

	ft_form(flag);
	if (flag->content == NULL && (*count += 6))
		ft_putstr("(null)");
	if (!(flag->flags['-']) && (*count += POPS(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
	i = -1;
	while (++i < flag->len && (*count += 1))
		ft_putchar(flag->content[i]);
	if ((flag->flags['-']) && (*count += POPS(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
}
