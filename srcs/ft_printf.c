/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 21:24:39 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 16:36:52 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *format, ...)
{
	va_list	*ap;
	int		ret;
	t_flag	*flag;

	va_start(ap, format);
	ft_get_info(format, ap, flag);
	va_end(ap);
	ret = ft_print_format(format, flag);
	return (ret);
}