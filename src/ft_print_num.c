/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:56:24 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:10 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_hex(unsigned long number)
{
	int	result;

	result = 1;
	if (number < 16)
	{
		ft_putchar_fd("0123456789abcdef"[number], 1);
		return (result);
	}
	else
	{
		result += ft_putunbr_hex(number / 16);
		ft_putchar_fd("0123456789abcdef"[number % 16], 1);
	}
	return (result);
}

void	ft_print_unsign(t_param *parameter)
{
	unsigned int	number;
	int				digits;

	number = (unsigned int) va_arg(parameter->args, unsigned int);
	digits = ft_putunbr(number);
	parameter->counter += digits;
	parameter->index += 1;
}

int	ft_putunbr(unsigned int number)
{
	int	result;

	result = 1;
	if (number < 10)
	{
		ft_putchar_fd(number + '0', 1);
		return (result);
	}
	else
	{
		result += ft_putunbr(number / 10);
		ft_putchar_fd((number % 10) + '0', 1);
	}
	return (result);
}
