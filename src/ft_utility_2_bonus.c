/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:44:54 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:46 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	printemptyspaces(int n)
{
	while (n-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_putunbr_pointer(unsigned long number)
{
	if (number < 16)
	{
		ft_putchar_fd("0123456789abcdef"[number], 1);
	}
	else
	{
		ft_putunbr_pointer(number / 16);
		ft_putchar_fd("0123456789abcdef"[number % 16], 1);
	}
}

void	ft_putunbr(unsigned long number)
{
	if (number < 10)
	{
		ft_putchar_fd(number + '0', 1);
	}
	else
	{
		ft_putunbr(number / 10);
		ft_putchar_fd((number % 10) + '0', 1);
	}
}
