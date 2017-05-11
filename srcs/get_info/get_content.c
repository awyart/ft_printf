/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:43:49 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 18:37:19 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "convert.h"

int			ft_get_content(t_flag *flag, va_list ap)
{
	int		j;
	t_conv	*test;

	test = g_conv;
	j = -1;
	while (++j < NB_OPTIONS)
	{
		if (flag->flag_type == test[j].status[0])
		{
			test[j].f(flag, ap);
			return (1);
		}
	}
	return (-1);
}