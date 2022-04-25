/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_spec_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:15:59 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:43:00 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_decode_specifer(char c, t_param *parameter)
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
	else if (c == '%')
		parameter->specifier = '%';
}

void	ft_decode_flag(char c, t_param *parameter)
{
	if (c == '-')
		parameter->minusflag = 1;
	else if (c == '+')
		parameter->plusflag = 1;
	else if (c == '0')
		parameter->zeroflag = 1;
	else if (c == '#')
		parameter->dashflag = 1;
	else if (c == ' ')
		parameter->spaceflag = 1;
	parameter->index += 1;
}

void	ft_decode_width(const char *input, t_param *parameter)
{
	int	result;
	int	width;

	result = 0;
	if (input[parameter->index] == '*')
	{
		width = va_arg(parameter->args, int);
		if (width < 0)
		{
			parameter->width = -1 * width;
			parameter->minusflag = 1;
		}
		else
			parameter->width = width;
		parameter->index += 1;
	}
	else
	{
		while (ft_isdigit(input[parameter->index]))
		{
			result = result * 10 + (input[parameter->index] - '0');
			parameter->index += 1;
		}
		parameter->width = result;
	}
}

void	ft_decode_precision(const char *input, t_param *parameter)
{
	int	result;
	int	precision;

	result = 0;
	parameter->index += 1;
	if (input[parameter->index] == '*')
	{
		precision = va_arg(parameter->args, int);
		if (precision >= 0)
		{
			parameter->dotflag = 1;
			parameter->precision = precision;
		}
		parameter->index += 1;
	}
	else
	{
		while (ft_isdigit(input[parameter->index]))
		{
			result = result * 10 + (input[parameter->index] - '0');
			parameter->index += 1;
		}
		parameter->dotflag = 1;
		parameter->precision = result;
	}
}
