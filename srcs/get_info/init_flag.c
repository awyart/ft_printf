/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:57:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 18:32:23 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			*ft_init_flag(t_flag *flag, char c)
{
	t_flag	*last;
	int		i;

	last = flag;
	i = 0;
	while (last)
	{
		if (c == last->flag_type)
			i++;
		last = last->next;
	}
	last = ft_newflag(void)
	last->nb_type = i;
}