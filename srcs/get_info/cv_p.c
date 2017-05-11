/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:43:40 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 18:48:46 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(t_flag *flag, va_list ap)
{
	flag->content = ft_itoab_ll((ULL)va_arg(ap, void *), 16);
	ft_down(flag->content);
	flag->len = ft_strlen(flag->content) + 2;
}