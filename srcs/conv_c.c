/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:56:50 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:12:19 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_c(t_flags *flags, va_list args)
{
	int		count;

	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar(va_arg(args, int));
		while (--flags->min_width)
			count += ft_putchar(' ');
	}
	else if (flags->min_width)
	{
		while (flags->zero && --flags->min_width)
			count += ft_putchar('0');
		while (!flags->zero && --flags->min_width)
			count += ft_putchar(' ');
		count += ft_putchar(va_arg(args, int));
	}
	else
		count += ft_putchar(va_arg(args, int));
	return (count);
}
