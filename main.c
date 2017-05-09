/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 22:32:50 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 19:47:08 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

int	main(void)
{
	long long int	i;
	int				ft_ret;
	int				ret;
	float			f;

	i = LLONG_MIN;
	f = 1. / 3.;
	ft_ret = ft_printf("%ji", -4294967296);
	ret = printf("\n%ji\n", -4294967296);
	printf("\nft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%jo", -4294967296);
	ret = printf("\n%jo\n", -4294967296);
	printf("\nft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%jd", -4294967296);
	ret = printf("\n%jd\n", -4294967296);
	printf("\nft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%jx", -4294967296);
	ret = printf("\n%jx\n", -4294967296);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%jx", -4294967297);
	ret = printf("\n%jx\n", -4294967297);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%010x", 542);
	ret = printf("\n%010x\n", 542);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%#lx", 9223372036854775807);
	ret = printf("\n%#lx\n", 9223372036854775807);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%#x", 0);
	ret = printf("\n%#x\n", 0);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%#08x", 42);
	ret = printf("\n%#08x\n", 42);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%#8x", 42);
	ret = printf("\n%#8x\n", 42);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%#6o", 2500);
	ret = printf("\n%#6o\n", 2500);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%lld", i);
	ret = printf("\n%lld\n", i);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%hd", 32768);
	ret = printf("\n%hd\n", 32768);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%hhd", 128);
	ret = printf("\n%hhd\n", 128);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%d", -5620);
	ret = printf("\n%d\n", -5620);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%x", -5620);
	ret = printf("\n%x\n", -5620);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%zd", 4294967295);
	ret = printf("\n%zd\n", 4294967295);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%zd", 4294967296);
	ret = printf("\n%zd\n", 4294967296);
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%lu", "-42");
	ret = printf("\n%lu\n", "-42");
	printf("ft_ret %d: ret :%d \n", ft_ret, ret - 2);
	ft_ret = ft_printf("%.2s is a string", "this");
	ret = printf("\n%.2s is a string\n", "this");
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("%-10.5o", 2500);
	ret = printf("\n%-10.5o\n", 2500) - 2;
	printf("ft_ret %d: ret :%d \n", ft_ret, ret);
	ft_ret = ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ret = printf("\n@moulitest: %#.x %#.0x", 0, 0);
	printf("\nft_ret %d: ret :%d \n", ft_ret, ret - 1);
	ft_ret = ft_printf("@moulitest: %s", NULL);
	ret = printf("\n@moulitest: %s", NULL);
	printf("\nft_ret %d: ret :%d \n", ft_ret, ret - 1);
	return (0);
}
