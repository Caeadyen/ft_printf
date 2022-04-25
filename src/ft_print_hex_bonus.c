/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:22:34 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:44:56 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_hex(t_param *parameter)
{
	unsigned int	number;

	number = (unsigned int) va_arg(parameter->args, unsigned int);
	if (number == 0 && parameter->dotflag && parameter->precision == 0)
		print_zero(parameter);
	else if (parameter->minusflag)
		print_hex_minus(parameter, number);
	else if (parameter->zeroflag && parameter->dotflag)
		print_hex_zero_dot(parameter, number);
	else if (parameter->dashflag)
		print_hex_dash(parameter, number);
	else
		print_hex(parameter, number);
}

void	print_hex(t_param *parameter, unsigned int number)
{
	int				digits;
	int				spaces;
	int				emptyspaces;

	digits = get_digits((long) number, 16);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspaces = parameter->width - spaces;
	parameter->counter += spaces;
	if (emptyspaces > 0)
	{
		ft_printspaces(parameter, emptyspaces);
		parameter->counter += emptyspaces;
	}
	ft_print_prec(spaces - digits);
	ft_putnbr_hex(number, parameter->specifier);
}

void	ft_putnbr_hex(unsigned int number, char low)
{
	if (number < 16)
	{
		if (low == 'x')
			ft_putchar_fd("0123456789abcdef"[number], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[number], 1);
	}
	else
	{
		ft_putnbr_hex(number / 16, low);
		if (low == 'x')
			ft_putchar_fd("0123456789abcdef"[number % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[number % 16], 1);
	}
}
