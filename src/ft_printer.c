/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:24:21 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:30 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

void	ft_print_percent(t_param *parameter)
{
	ft_putchar_fd('%', 1);
	parameter->counter += 1;
	parameter->index += 1;
}

void	ft_print_char(t_param *parameter)
{
	int	c;

	c = va_arg(parameter->args, int);
	parameter->counter += 1;
	parameter->index += 1;
	ft_putchar_fd((char) c, 1);
}

void	ft_print_str(t_param *parameter)
{
	char	*str;

	str = va_arg(parameter->args, char *);
	if (str)
	{
		parameter->counter += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		parameter->counter += 6;
	}
	parameter->index += 1;
}
