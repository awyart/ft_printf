/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:03:20 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 14:06:38 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_countbits(unsigned int c)
{
	unsigned int i;

	if (c == 0)
		return (1);
	i = 0;
	while (c > 0)
	{
		i++;
		c = c >> 1;
	}
	return (i);
}

static void		ft_print_3(int letter[4], unsigned int c)
{
	letter[0] = 0xE0 | (c >> 12);
	letter[1] = 0x80 | (0x3F & c >> 6);
	letter[2] = 0x80 | (0x3F & c);
	write(1, letter, 3);
}

static void		ft_print_4(int letter[4], unsigned int c)
{
	letter[0] = 0xF0 | (c >> 18);
	letter[1] = 0x80 | (0x3F & c >> 12);
	letter[2] = 0x80 | (0x3F & c >> 6);
	letter[3] = 0x80 | (0x3F & c);
	write(1, letter, 4);
}

void			ft_putchar_unicode(unsigned int c)
{
	unsigned int	i;
	int				letter[4];

	i = ft_countbits(c);
	if (i < 8)
	{
		letter[0] = c;
		write(1, letter, 1);
	}
	if (i < 12)
	{
		letter[0] = 0xC0 | (c >> 6);
		letter[1] = 0x80 | (0x3F & c);
		write(1, letter, 2);
	}
	if (i < 18)
		ft_print_3(letter, c);
	if (i < 22)
		ft_print_4(letter, c);
}
