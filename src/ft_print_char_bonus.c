/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:39:54 by hrings            #+#    #+#             */
/*   Updated: 2022/02/09 09:44:52 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_char(t_param *parameter)
{
	int	c;
	int	emptyspaces;

	c = va_arg(parameter->args, int);
	emptyspaces = parameter->width -1;
	if (parameter->minusflag)
	{
		ft_putchar_fd((char) c, 1);
		printemptyspaces(emptyspaces);
	}
	else
	{
		printemptyspaces(emptyspaces);
		ft_putchar_fd((char) c, 1);
	}
	if (parameter->width != 0)
		parameter->counter += parameter->width;
	else
		parameter->counter += 1;
}
