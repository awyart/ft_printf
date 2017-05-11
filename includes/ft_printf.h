/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:37:22 by awyart            #+#    #+#             */
/*   Updated: 2017/05/11 19:31:47 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MIN	-2147483648
# define OPTIONS "sSpdDioOuUxXcCbB"
# define FLAG1	"#+- 0"
# define FLAG2	"lhjzt."
# define NB_OPTIONS	ft_strlen(OPTIONS)
# define POPS(value) ((value <= 0) ? 0 : value)
# define ULL unsigned long long
# define LL long long

typedef struct			s_flag
{
	char				content[4096];
	int					len;
	char				flag_type;
	int					nb_type;
	int					width;
	int					precision;
	char				flags[128];
	struct s_flag		next;
}						t_flag;

typedef struct			s_next
{
	char				*status;
	void				(*f)(t_flag flag, int *count);
}						t_next;

typedef struct			s_conv
{
	char				*status;
	void				(*f)(t_flag *flag, va_list ap);
}						t_conv;

//utility
void					ft_putchar(char c);
void					ft_putnchar(int n, char c);
void					ft_putstr(char const *s);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_itoa(long long value);
char					*ft_itoab_ll(unsigned long long value, int base);
void					ft_down(char *str);

//main
int						ft_printf(char *str, ...);

//get_info
void					ft_get_info(char *format, va_list ap, t_flag *flag);
int						ft_get_flag(t_flag *flag, char *format, va_list ap);
void					ft_init_flag(t_flag *flag, char c);
int						ft_get_content(t_flag *flag, va_list ap);
void					conv_s(t_flag *flag, va_list ap);
void					conv_d(t_flag *flag, va_list ap);
void					conv_dm(t_flag *flag, va_list ap);
void					conv_p(t_flag *flag, va_list ap);
void					conv_o(t_flag *flag, va_list ap);
void					conv_om(t_flag *flag, va_list ap);
void					conv_u(t_flag *flag, va_list ap);
void					conv_um(t_flag *flag, va_list ap);
void					conv_x(t_flag *flag, va_list ap);
void					conv_xm(t_flag *flag, va_list ap);

//print
int						ft_print_format(char *format, t_flag flag);
int						ft_print_flag(char *format, t_flag flag, int *count);
void					ft_s(t_flag *flag, int *count);
void					ft_sm(t_flag *flag, int *count);
void					ft_p(t_flag *flag, int *count);
void					ft_d(t_flag *flag, int *count);
void					ft_o(t_flag *flag, int *count);
void					ft_u(t_flag *flag, int *count);
void					ft_c(t_flag *flag, int *count);
void					ft_cm(t_flag *flag, int *count);
void					ft_b(t_flag *flag, int *count);
void					ft_bm(t_flag *flag, int *count);

//detect
void					ft_putspe(t_flag flag,
							char type, int *count, int nb);

#endif
