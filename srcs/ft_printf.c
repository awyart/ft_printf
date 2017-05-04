/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 22:06:38 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 18:30:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	free_flag(t_flag *flag)
{
	return (1);
	if (flag != NULL)
	{
		ft_strdel(&(flag->content));
		ft_strdel(&(flag->flags));
		free(flag);
	}
}

int			ft_start(char *format, va_list ap)
{
	int		i;
	t_flag	*flag;
	int		test_error;
	int		count;

	i = -1;
	test_error = 0;
	count = 0;
	while (format[++i] != '\0')
		if (format[i] == '%')
		{
			flag = ft_get_next(format + i, ap, &test_error);
			if (test_error == 1)
			{
				ft_putstr("Error get flags\n");
				return (-1);
			}
			count = count + flag->len;
			i = i + flag->flag_len;
			free_flag(flag);
		}
		else if ((count += 1))
			ft_putchar(format[i]);
	return (count);
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_start(format, ap);
	va_end(ap);
	return (ret);
}
