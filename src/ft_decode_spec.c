/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:15:59 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:44:48 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_flags(t_param *parameter);
static void	decode_specifer(char c, t_param *parameter);

void	ft_decode_specifer(const char *input, t_param *parameter)
{
	if ((char) input[parameter->index] == '%')
		ft_print_percent(parameter);
	else
	{
		decode_specifer(input[parameter->index], parameter);
		ft_printer(parameter);
		reset_flags(parameter);
	}
}

static void	reset_flags(t_param *parameter)
{
	parameter->specifier = 0;
}

static void	decode_specifer(char c, t_param *parameter)
{
	if (c == 'c')
		parameter->specifier = 'c';
	else if (c == 's')
		parameter->specifier = 's';
	else if (c == 'p')
		parameter->specifier = 'p';
	else if (c == 'd')
		parameter->specifier = 'd';
	else if (c == 'i')
		parameter->specifier = 'i';
	else if (c == 'u')
		parameter->specifier = 'u';
	else if (c == 'x')
		parameter->specifier = 'x';
	else if (c == 'X')
		parameter->specifier = 'X';
}
