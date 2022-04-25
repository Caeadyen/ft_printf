/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_parameter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:53:13 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:42:34 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_isflag(char c);
static void	ft_reset_flags(t_param *parameter);

void	ft_decode_parameter(const char *input, t_param *parameter)
{
	while (ft_isflag(input[parameter->index]))
		ft_decode_flag(input[parameter->index], parameter);
	if (ft_isdigit(input[parameter->index]))
		ft_decode_width(input, parameter);
	if (input[parameter->index] == '*')
		ft_decode_width(input, parameter);
	if ((char) input[parameter->index] == '.')
		ft_decode_precision(input, parameter);
	ft_decode_specifer(input[parameter->index], parameter);
	ft_printer(parameter);
	ft_reset_flags(parameter);
}

static int	ft_isflag(char c)
{
	int	result;

	result = 0;
	if (c == '-')
		result++;
	else if (c == '0')
		result++;
	else if (c == '#')
		result++;
	else if (c == ' ')
		result++;
	else if (c == '+')
		result++;
	return (result);
}

static void	ft_reset_flags(t_param *parameter)
{
	parameter->minusflag = 0;
	parameter->zeroflag = 0;
	parameter->dotflag = 0;
	parameter->dashflag = 0;
	parameter->spaceflag = 0;
	parameter->plusflag = 0;
	parameter->width = 0;
	parameter->specifier = 0;
	parameter->precision = 0;
}
