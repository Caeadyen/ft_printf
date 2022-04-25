/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:38:24 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:45:19 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	putstr(char const *s, int len);
static void	print_str(char const *str, t_param *parameter, int length);
static void	print_spaces(t_param *parameter);

void	ft_print_str(t_param *parameter)
{
	char	*str;
	int		length;

	str = va_arg(parameter->args, char *);
	if (str)
	{
		length = ft_strlen(str);
		if (parameter->dotflag && parameter->precision < length)
			length = parameter->precision;
		print_str(str, parameter, length);
	}
	else
	{
		length = 6;
		if (parameter->dotflag && parameter->precision < length)
			length = parameter->precision;
		print_str("(null)", parameter, length);
	}
}

static	void	print_str(char const *str, t_param *parameter, int length)
{
	if (parameter->minusflag)
	{
		putstr(str, length);
		parameter->counter += length;
		parameter->width -= length;
		print_spaces(parameter);
	}
	else
	{
		parameter->width -= length;
		print_spaces(parameter);
		putstr(str, length);
		parameter->counter += length;
	}
}

static void	putstr(char const *s, int len)
{
	if (s && *s && len > 0)
	{
		ft_putchar_fd(*s, 1);
		putstr(++s, len - 1);
	}
}

static void	print_spaces(t_param *parameter)
{
	while (parameter->width > 0)
	{
		ft_putchar_fd(' ', 1);
		parameter->counter += 1;
		parameter->width -= 1;
	}
}
