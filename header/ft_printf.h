/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:13:17 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:43:15 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_parameter
{
	int		counter;
	int		index;
	char	specifier;
	va_list	args;
}			t_param;
int			ft_printf(const char *input, ...);
void		ft_decode_specifer(const char *input, t_param *parameter);
void		ft_printer(t_param *parameter);
void		ft_print_percent(t_param *parameter);
void		ft_print_char(t_param *parameter);
void		ft_print_str(t_param *parameter);
void		ft_print_int(t_param *parameter);
void		ft_print_hex(t_param *parameter);
void		ft_print_pointer(t_param *parameter);
int			ft_putunbr_hex(unsigned long number);
int			ft_putnbr_hex(unsigned int number, char low);
void		ft_print_unsign(t_param *parameter);
int			ft_putunbr(unsigned int number);

#endif
