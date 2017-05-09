/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:45:16 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 19:39:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "detect.h"

int		ft_detect(t_flag *flag, va_list ap)
{
	int		j;
	t_next	*test;

	test = g_ouch;
	j = -1;
	while (++j < NB_OPTIONS)
	{
		if (flag->flag_type == test[j].status[0])
		{
			test[j].f(flag, ap);
			return (1);
		}
	}
	return (0);
}

int		ft_end_flag(char c)
{
	t_next	*test;
	int		i;

	test = g_ouch;
	i = -1;
	while (++i < NB_OPTIONS)
	{
		if (c == test[i].status[0])
			return (0);
	}
	return (1);
}

int		ft_count_arg(char *str)
{
	int		count;
	int		i;
	t_next	*test;
	int		j;

	count = 0;
	i = 0;
	test = g_ouch;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			j = 0;
			while (j < NB_OPTIONS)
			{
				if (str[i + 1] == test[j].status[0])
					count++;
				j++;
			}
		}
		i++;
	}
	return (count);
}
