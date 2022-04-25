/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:27:32 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:03 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_digits(int n);

void	ft_print_int(t_param *parameter)
{
	int		number;

	number = va_arg(parameter->args, int);
	ft_putnbr_fd(number, 1);
	parameter->counter += get_digits(number);
	parameter->index += 1;
}

void	ft_print_hex(t_param *parameter)
{
	unsigned int	number;
	int				digits;

	number = (unsigned int) va_arg(parameter->args, unsigned int);
	digits = ft_putnbr_hex(number, parameter->specifier);
	parameter->counter += digits;
	parameter->index += 1;
}

void	ft_print_pointer(t_param *parameter)
{
	unsigned long	pointer;
	int				digits;

	pointer = va_arg(parameter->args, unsigned long);
	if (!pointer)
	{
		ft_putstr_fd("0x0", 1);
		digits = 1;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		digits = ft_putunbr_hex(pointer);
	}
	parameter->counter += digits + 2;
	parameter->index += 1;
}

static size_t	get_digits(int n)
{
	size_t	digits_r;

	digits_r = 1;
	if (n < 0)
		digits_r++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		digits_r++;
	}
	return (digits_r);
}

int	ft_putnbr_hex(unsigned int number, char low)
{
	int	result;

	result = 1;
	if (number < 16)
	{
		if (low == 'x')
			ft_putchar_fd("0123456789abcdef"[number], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[number], 1);
		return (result);
	}
	else
	{
		result += ft_putnbr_hex(number / 16, low);
		if (low == 'x')
			ft_putchar_fd("0123456789abcdef"[number % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[number % 16], 1);
	}
	return (result);
}
