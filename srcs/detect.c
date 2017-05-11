/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:49:32 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 15:34:48 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "detect.h"

void		ft_putspe(t_flag *flag, char type, int *count, int nb)
{
	int		j;
	t_next	*test;

	test = g_ouch;
	j = -1;
	while (flag->flag_type != type && flag->nb_type != nb)
	{
		flag = flag->next;
	}
	while (++j < NB_OPTIONS)
	{
		if (type == test[j]->status[0])
			test[j].f(flag, count);
	}
}
