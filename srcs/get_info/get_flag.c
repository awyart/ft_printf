/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:25:26 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 18:22:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_width(t_flag *flag, va_list ap, char *str, int *i)
{
	int n;

	n = 0;
	if (str[*i] == '*' || ft_isdigit(str[*i]))
	{
		if (str[*i] == '*')
			n = va_arg(ap, int);
		else
		{
			while (ft_isdigit(str[*i]))
				n = ((int)str[(*i)++] - '0') + n * 10;
			flag->width = n;
		}
	}
}

static void		ft_get_precision(t_flag *flag, va_list ap, char *str, int *i)
{
	int n;

	n = 0;
	if (str[*i] == '.')
	{
		if (str[*i + 1] == '*' || ft_isdigit(str[*i + 1]))
		{
			(*i)++;
			if (str[*i] == '*')
				n = va_arg(ap, int);
			else
			{
				while (ft_isdigit(str[*i]))
					n = (str[(*i)++] - '0') + n * 10;
				flag->precision = n;
			}
		}
		else
			flag->precision = 0;
	}
}

static void		ft_get_modif(t_flag *flag, char *test, char *str, int *i)
{
	while (ft_strchr(test, str[*i]))
		(flag->flags[(int)str[(*i)++]]) += 1;
}

int				ft_get_flag(t_flag *flag, char *format, va_list ap)
{
	int		i;
	t_flag	*w

	i = 0;
	while (format[++i])
		if (ft_strchr(OPTIONS,format[i]))
			break ;
	if (format[i] == '\0')
		return (-1);
	wflag = ft_init_flag(wflag, format[i]);
	i = 1;
	ft_get_modif(wflag, FLAG1, format, &i);
	ft_get_width(wflag, ap, format, &i);
	ft_get_precision(wflag, ap, format, &i);
	ft_get_modif(wflag, FLAG2, format, &i);
	if (ft_strchr(OPTIONS, format[i]) == NULL)
		return (-1);
	wflag->flag_len = i;
	wflag->flag_type = format[i];
	ft_get_content(wflag, ap);
	return (1);
}