/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:24:21 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:27 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_percent(t_param *parameter);

void	ft_printer(t_param *parameter)
{
	if (parameter->specifier == 'c')
		ft_print_char(parameter);
	else if (parameter->specifier == 's')
		ft_print_str(parameter);
	else if (parameter->specifier == 'd' || parameter->specifier == 'i')
		ft_print_int(parameter);
	else if (parameter->specifier == 'x' || parameter->specifier == 'X')
		ft_print_hex(parameter);
	else if (parameter->specifier == 'p')
		ft_print_pointer(parameter);
	else if (parameter->specifier == 'u')
		ft_print_unsign(parameter);
	else if (parameter->specifier == '%')
		print_percent(parameter);
	parameter->index += 1;
}

static void	print_percent(t_param *parameter)
{
	ft_putchar_fd('%', 1);
	parameter->counter += 1;
}
