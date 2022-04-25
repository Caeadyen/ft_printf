/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:56:24 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:23 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_unsign(t_param *parameter)
{
	unsigned int	number;

	number = (unsigned int) va_arg(parameter->args, unsigned int);
	if (number == 0 && parameter->dotflag && parameter->precision == 0)
		print_zero(parameter);
	else if (parameter->minusflag)
		print_uns_minus(parameter, number);
	else if (parameter->zeroflag && parameter->dotflag)
		print_uns_zoro_dot(parameter, number);
	else if (parameter->zeroflag)
		print_zeroflag_uns(parameter, number);
	else
		print_uns(parameter, number);
}

void	print_uns(t_param *parameter, unsigned int number)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - spaces;
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	printemptyspaces(emptyspace);
	ft_print_prec(spaces - digits);
	ft_putunbr(number);
	parameter->counter += spaces;
}
