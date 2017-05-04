/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:37:22 by awyart            #+#    #+#             */
/*   Updated: 2017/05/04 16:07:17 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MIN	-2147483648
# define FLGS_1	"+- 0"
# define FLGS_2	"lh"
# define NB_OPTIONS	16

typedef struct	s_flag
{
	char		*content;
	int			len;
	int			flag_len;
	char		flag_type;
	int			width;
	int			precision;
	char		*flags;
}				t_flag;

typedef struct	s_next
{
	char		*status;
	void		(*f)(t_flag *flag, va_list ap, int *test_error);
}				t_next;

int				ft_printf(char *str, ...);
void			put_s(t_flag *flag);
void			put_d(t_flag *flag);
void			put_d_unicode(t_flag *flag);
void			put_s_unicode(t_flag *flag);
int				ft_detect(t_flag *flag, va_list ap, int *test_error);
int				ft_count_arg(char *str);
t_flag			*ft_get_next(char *str, va_list ap, int *test_error);
int				ft_end_flag(char c);
int				ft_isdigit(int c);
char			*ft_itoab_ll(long long value, int base);
char			*ft_itoab_ll_s(long long value, int base);
void			ft_putchar(char c);
void			ft_putchar_unicode(unsigned int c);
void			ft_putnchar(int n, char c);
void			ft_putnchar_unicode(int n, char c);
void			ft_putstr(char const *s);
void			ft_strdel(char **as);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
void			ft_s(t_flag *flag, va_list ap, int *test_error);
void			ft_s_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_p(t_flag *flag, va_list ap, int *test_error);
void			ft_d(t_flag *flag, va_list ap, int *test_error);
void			ft_d_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_i(t_flag *flag, va_list ap, int *test_error);
void			ft_o(t_flag *flag, va_list ap, int *test_error);
void			ft_o_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_u(t_flag *flag, va_list ap, int *test_error);
void			ft_u_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_x(t_flag *flag, va_list ap, int *test_error);
void			ft_x_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_c(t_flag *flag, va_list ap, int *test_error);
void			ft_c_maj(t_flag *flag, va_list ap, int *test_error);
void			ft_per(t_flag *flag, va_list ap, int *test_error);
void			ft_b(t_flag *flag, va_list ap, int *test_error);

#endif
