/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:25:34 by hrings            #+#    #+#             */
/*   Updated: 2022/02/12 12:05:08 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_hex_minus(t_param *parameter, unsigned int number)
{
	int				digits;
	int				spaces;
	int				emptyspaces;

	digits = get_digits((long) number, 16);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspaces = parameter->width - spaces;
	ft_print_prec(spaces - digits);
	ft_putnbr_hex(number, parameter->specifier);
	parameter->counter += spaces;
	if (emptyspaces > 0)
	{
		printemptyspaces(emptyspaces);
		parameter->counter += emptyspaces;
	}
}

void	print_hex_zero_dot(t_param *parameter, unsigned int number)
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
		printemptyspaces(emptyspaces);
		parameter->counter += emptyspaces;
	}
	ft_print_prec(spaces - digits);
	ft_putnbr_hex(number, parameter->specifier);
}

void	print_hex_dash(t_param *parameter, unsigned int number)
{
	int				digits;
	int				spaces;

	digits = get_digits((long) number, 16);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	if (number != 0)
	{
		ft_putchar_fd('0', 1);
		if (parameter->specifier == 'x')
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
		parameter->counter += 2;
	}
	ft_putnbr_hex(number, parameter->specifier);
	parameter->counter += spaces;
}
