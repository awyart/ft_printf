/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:18:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 15:33:33 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_print_format(char *format, t_flag *flag)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			if (*(format + 1) == '%')
			{
				ft_putchar('%');
				i++;
				count++;
			}
			else
				ft_print_flag(format, flag, &count);
		else
			ft_putchar(*format);
		format++;
		count++;
		i = 1;
	}
	return (count);
}
