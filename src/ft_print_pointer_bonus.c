/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:20 by hrings            #+#    #+#             */
/*   Updated: 2022/02/12 13:46:01 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_pointer(t_param *parameter)
{
	unsigned long	pointer;

	pointer = va_arg(parameter->args, unsigned long);
	if (!pointer)
		pointer = 0;
	if (parameter->minusflag)
		print_pointer_minus(parameter, pointer);
	else
		print_pointer(parameter, pointer);
}

void	print_pointer_minus(t_param *parameter, unsigned long pointer)
{
	int			digits;
	int			emptyspaces;

	digits = get_digits_pointer(pointer) + 2;
	ft_putstr_fd("0x", 1);
	ft_putunbr_pointer(pointer);
	parameter->counter += digits;
	emptyspaces = parameter->width - digits;
	if (emptyspaces > 0)
	{
		printemptyspaces(emptyspaces);
		parameter->counter += emptyspaces;
	}
}

void	print_pointer(t_param *parameter, unsigned long pointer)
{
	int			digits;
	int			emptyspaces;

	digits = get_digits_pointer(pointer) + 2;
	parameter->counter += digits;
	emptyspaces = parameter->width - digits;
	if (emptyspaces > 0)
	{
		printemptyspaces(emptyspaces);
		parameter->counter += emptyspaces;
	}
	ft_putstr_fd("0x", 1);
	ft_putunbr_pointer(pointer);
}
