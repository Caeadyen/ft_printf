/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:13:17 by hrings            #+#    #+#             */
/*   Updated: 2022/02/12 13:36:47 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_parameter
{
	int		counter;
	int		index;
	int		minusflag;
	int		zeroflag;
	int		dotflag;
	int		dashflag;
	int		spaceflag;
	int		plusflag;
	int		width;
	int		precision;
	char	specifier;
	va_list	args;
}			t_param;
int			ft_printf(const char *input, ...);
void		ft_decode_parameter(const char *input, t_param *parameter);
void		ft_decode_specifer(char c, t_param *parameter);
void		ft_decode_flag(char c, t_param *parameter);
void		ft_decode_width(const char *input, t_param *parameter);
void		ft_decode_precision(const char *input, t_param *parameter);
void		ft_putunint(unsigned long number);
void		ft_print_prec(int num);
void		ft_printspaces(t_param *parameter, int num);
int			get_digits(long n, int base);
int			get_digits_pointer(unsigned long n);
void		printemptyspaces(int n);
void		ft_putunbr_pointer(unsigned long number);
void		ft_putunbr(unsigned long number);
void		ft_printer(t_param *parameter);
void		ft_print_char(t_param *parameter);
void		ft_print_str(t_param *parameter);
void		ft_print_int(t_param *parameter);
void		ft_print_hex(t_param *parameter);
void		ft_print_pointer(t_param *parameter);
void		ft_print_unsign(t_param *parameter);
void		ft_putunbr_hex(unsigned long number);
void		print_hex(t_param *parameter, unsigned int number);
void		ft_putnbr_hex(unsigned int number, char low);
void		print_hex_minus(t_param *parameter, unsigned int number);
void		print_hex_zero_dot(t_param *parameter, unsigned int number);
void		print_hex_dash(t_param *parameter, unsigned int number);
void		print_zero(t_param *parameter);
void		print_int_minus(t_param *parameter, long number, int sign);
void		print_int_zoro_dot(t_param *parameter, long number, int sign);
void		print_zeroflag(t_param *parameter, long number, int sign);
void		print_int(t_param *parameter, long number, int sign);
void		printlead(t_param *parameter, int sign);
int			getsignspace(t_param *parameter, int sign);
void		print_uns(t_param *parameter, unsigned int number);
void		print_uns_minus(t_param *parameter, unsigned int number);
void		print_uns_zoro_dot(t_param *parameter, unsigned int number);
void		print_zeroflag_uns(t_param *parameter, unsigned int number);
void		print_pointer_minus(t_param *parameter, unsigned long pointer);
void		print_pointer(t_param *parameter, unsigned long pointer);

#endif
