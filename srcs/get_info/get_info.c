/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:12:43 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 17:24:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag					*ft_get_info(char *format, va_list ap)
{
	int		i;
	t_flag	*flag;

	i = -1;
	while (format[++i] != '\0')
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				get_flag(flag, format + i, ap);
			}
			else
				i++;
		}
	return (flag);
}
