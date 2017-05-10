/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:46:30 by awyart            #+#    #+#             */
/*   Updated: 2017/05/10 18:59:46 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	*ft_newflag(void)
{
	t_flag	*flag;

	if (!(flag = malloc(sizeof(t_flag))))
		exit(0);
	if (!(flag->content = ft_strnew(43)))
		exit(0);
	if (!(flag->flags = ft_strnew(128 * sizeof(char))))
		exit(0);
	flag->len = 0;
	flag->flag_len = 0;
	flag->final_len = 0;
	flag->width = INT_MIN;
	flag->precision = INT_MIN;
	return (flag);
}

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

static void		ft_get_flags(t_flag *flag, char *test, char *str, int *i)
{
	while (ft_strchr(test, str[*i]))
		(flag->flags[(int)str[(*i)++]]) += 1;
}

t_flag			*ft_get_next(char *str, va_list ap)
{
	t_flag	*flag;
	int		i;
	int		percent;

	i = 1;
	percent = 0;
	if (!(flag = ft_newflag()))
		exit(0);
	if (ft_end_flag(str[i]))
	{
		ft_get_flags(flag, FLAG1, str, &i);
		ft_get_width(flag, ap, str, &i);
		ft_get_precision(flag, ap, str, &i);
		ft_get_flags(flag, FLAG2, str, &i);
	}
	flag->flag_len = i;
	flag->flag_type = str[i];
	if (!(ft_detect(flag, ap)))
		exit(0);
	return (flag);
}
