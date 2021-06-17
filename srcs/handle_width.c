/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:04:48 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:15:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		do_cardinal(t_flags *flags, int count)
{
	count += ft_putchar('0');
	if (flags->type == 'x')
		count += ft_putchar('x');
	else if (flags->type == 'X')
		count += ft_putchar('X');
	flags->cardinal = 0;
	return (count);
}

static int		do_zero(t_flags *flags, int count)
{
	if (flags->plus == 2)
		count += ft_putchar('+');
	else if (flags->space == 2)
		count += ft_putchar(' ');
	return (count);
}

int				handle_width(t_flags *flags, int len)
{
	int			count;

	count = 0;
	if (!flags->zero)
		while (flags->min_width-- > len)
			count += ft_putchar(' ');
	if (flags->cardinal == 2)
	{
		count = do_cardinal(flags, count);
		len += 2;
	}
	if (flags->zero)
	{
		if (flags->plus == 2 || flags->space == 2)
		{
			count = do_zero(flags, count);
			len++;
		}
		while (flags->min_width-- > len)
			count += ft_putchar('0');
	}
	return (count);
}
