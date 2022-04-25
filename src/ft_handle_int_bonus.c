/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:59:35 by hrings            #+#    #+#             */
/*   Updated: 2022/02/12 12:37:18 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_zero(t_param *parameter)
{
	printemptyspaces(parameter->width);
	parameter->counter += parameter->width;
}

void	print_int_minus(t_param *parameter, long number, int sign)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - (spaces + getsignspace(parameter, sign));
	printlead(parameter, sign);
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
	if (emptyspace > 0)
	{
		printemptyspaces(emptyspace);
		parameter->counter += emptyspace;
	}
}

void	print_int_zoro_dot(t_param *parameter, long number, int sign)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - (spaces + getsignspace(parameter, sign));
	printemptyspaces(emptyspace);
	printlead(parameter, sign);
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
}

void	print_zeroflag(t_param *parameter, long number, int sign)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - (spaces + getsignspace(parameter, sign));
	printlead(parameter, sign);
	ft_printspaces(parameter, emptyspace);
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
}
