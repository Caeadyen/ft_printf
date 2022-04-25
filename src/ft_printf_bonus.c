/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:10:54 by hrings            #+#    #+#             */
/*   Updated: 2022/02/16 13:35:00 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	initparameter(t_param *parameter);

int	ft_printf(const char *input, ...)
{
	t_param	*parameter;
	int		result;

	if (!input)
		return (-1);
	parameter = (t_param *)malloc(sizeof(t_param));
	if (!parameter)
		return (-1);
	initparameter(parameter);
	va_start(parameter->args, input);
	while (input && input[parameter->index])
	{
		if ((char) input[parameter->index] != '%')
		{
			ft_putchar_fd(input[parameter->index++], 1);
			parameter->counter++;
		}
		else if ((char) input[parameter->index++] == '%')
			ft_decode_parameter(input, parameter);
	}
	va_end(parameter->args);
	result = parameter->counter;
	free(parameter);
	return (result);
}

static void	initparameter(t_param *parameter)
{
	parameter->counter = 0;
	parameter->index = 0;
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
