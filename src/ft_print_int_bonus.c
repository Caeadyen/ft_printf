/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:27:32 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:44:59 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_int(t_param *parameter)
{
	long	number;
	int		sign;

	number = (long) va_arg(parameter->args, int);
	sign = 0;
	if (number < 0)
		sign = 1;
	if (sign)
		number *= -1;
	if (number == 0 && parameter->dotflag && parameter->precision == 0)
		print_zero(parameter);
	else if (parameter->minusflag)
		print_int_minus(parameter, number, sign);
	else if (parameter->zeroflag && parameter->dotflag)
		print_int_zoro_dot(parameter, number, sign);
	else if (parameter->zeroflag)
		print_zeroflag(parameter, number, sign);
	else
		print_int(parameter, number, sign);
}

void	print_int(t_param *parameter, long number, int sign)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - (spaces + getsignspace(parameter, sign));
	ft_printspaces(parameter, emptyspace);
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	printlead(parameter, sign);
	ft_print_prec(spaces - digits);
	ft_putunint(number);
	parameter->counter += spaces;
}

int	getsignspace(t_param *parameter, int sign)
{
	if (sign)
		return (1);
	else if (parameter->plusflag)
		return (1);
	else if (parameter->spaceflag)
		return (1);
	return (0);
}

void	printlead(t_param *parameter, int sign)
{
	if (sign)
	{
		ft_putchar_fd('-', 1);
		parameter->counter += 1;
	}
	else if (parameter->plusflag)
	{
		ft_putchar_fd('+', 1);
		parameter->counter += 1;
	}
	else if (parameter->spaceflag)
	{
		ft_putchar_fd(' ', 1);
		parameter->counter += 1;
	}
}
