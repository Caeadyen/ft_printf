/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uns_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:47:37 by hrings            #+#    #+#             */
/*   Updated: 2022/02/12 12:04:21 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_uns_minus(t_param *parameter, unsigned int number)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - spaces;
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
	if (emptyspace > 0)
	{
		printemptyspaces(emptyspace);
		parameter->counter += emptyspace;
	}
}

void	print_uns_zoro_dot(t_param *parameter, unsigned int number)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - spaces;
	printemptyspaces(emptyspace);
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
}

void	print_zeroflag_uns(t_param *parameter, unsigned int number)
{
	int	digits;
	int	spaces;
	int	emptyspace;

	digits = (int) get_digits(number, 10);
	spaces = digits;
	if (spaces < parameter->precision)
		spaces = parameter->precision;
	emptyspace = parameter->width - spaces;
	ft_printspaces(parameter, emptyspace);
	if (emptyspace > 0)
		parameter->counter += emptyspace;
	ft_print_prec(spaces - digits);
	ft_putunint((unsigned long) number);
	parameter->counter += spaces;
}
