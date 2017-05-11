/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:47:24 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 17:36:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_flag(char *format, t_flag *flag, int *count)
{
	char	type;
	int		nb;

	nb = 0;
	while (ft_strchr(OPTIONS, *format) == NULL)
	{
		if (*(format + 1) == '$')
		{
			if (ft_isdigit(*format))
				nb = *format - '0';
			else
				return (-1);
		}
		i++;
	}
	type = *format;
	ft_putspe(flag, type, count, nb);
	return (1);
}


