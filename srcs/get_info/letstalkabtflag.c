/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letstalkabtflag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:23:42 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 18:30:31 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_newflag(void)
{
	t_flag	*flag;

	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		exit(0);
	i = 0;
	while (++i < 4096)
		if (i < 128)
			flag->flags[i] = 0;
		flag->content[i] = '\0';
	flag->len = 0;
	flag->nb_type = 0;
	flag->flag_type = 0;
	flag->width = INT_MIN;
	flag->precision = INT_MIN;
	return (flag);
}

void		free_flag(t_flag *flag)
{
	return ;
	if (flag != NULL)
	{
		ft_strdel(&(flag->content));
		ft_strdel(&(flag->flags));
		free(flag);
	}
}