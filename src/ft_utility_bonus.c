/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:03:19 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:51 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putunint(unsigned long number)
{
	if (number < 10)
		ft_putchar_fd(number + '0', 1);
	else
	{
		ft_putunint(number / 10);
		ft_putchar_fd((number % 10) + '0', 1);
	}
}

void	ft_print_prec(int num)
{
	while (num > 0)
	{
		ft_putchar_fd('0', 1);
		num--;
	}
}

void	ft_printspaces(t_param *parameter, int num)
{
	char	c;

	if (parameter->zeroflag)
		c = '0';
	else
		c = ' ';
	while (num > 0)
	{
		ft_putchar_fd(c, 1);
		num--;
	}
}

int	get_digits(long n, int base)
{
	int	digits_r;

	digits_r = 1;
	while (n >= base || n <= -base)
	{
		n /= base;
		digits_r++;
	}
	return (digits_r);
}

int	get_digits_pointer(unsigned long n)
{
	int	digits_r;

	digits_r = 1;
	while (n >= 16)
	{
		n /= 16;
		digits_r++;
	}
	return (digits_r);
}
