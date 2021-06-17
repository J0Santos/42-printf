/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:58:45 by josantos          #+#    #+#             */
/*   Updated: 2021/03/29 14:53:24 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*handle_cardinal(char *p, t_flags *flags)
{
	char		*temp;

	if (!flags->cardinal)
		return (p);
	if (flags->zero)
		flags->cardinal = 2;
	if (flags->cardinal == 1)
	{
		if (flags->type == 'x')
		{
			temp = p;
			p = ft_strjoin("0x", p);
			free(temp);
		}
		else if (flags->type == 'X')
		{
			temp = p;
			p = ft_strjoin("0X", p);
			free(temp);
		}
	}
	return (p);
}

static char		*handle_zero(t_flags *flags, int *count, char *p)
{
	char		*temp;

	if (flags->point)
		flags->zero = 0;
	else if (p[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		temp = p;
		p = ft_substr(p, 1, (int)ft_strlen(p));
		flags->min_width -= 1;
		free(temp);
	}
	return (p);
}

static char		*handle_sign(char *p, t_flags *flags)
{
	if (p[0] == '-')
		p = handle_neg(flags, p);
	else
		p = handle_pos(flags, p);
	return (p);
}

static void		conv_x_intern(char *p, t_flags *flags, int *count)
{
	if (flags->minus && flags->min_width > (int)ft_strlen(p))
	{
		*count += ft_putstr(p);
		*count += handle_width(flags, (int)ft_strlen(p));
	}
	else if (flags->min_width > (int)ft_strlen(p))
	{
		*count += handle_width(flags, (int)ft_strlen(p));
		*count += ft_putstr(p);
	}
	else
	{
		if (flags->cardinal == 2)
		{
			*count += ft_putchar('0');
			*count += ft_putchar(flags->type);
		}
		*count += ft_putstr(p);
	}
}

int				conv_x(t_flags *flags, va_list args)
{
	int			count;
	char		*p;

	count = 0;
	p = arg_conversion(flags, args);
	if (*p == '0')
		flags->cardinal = 0;
	p = handle_zero(flags, &count, p);
	p = handle_sign(p, flags);
	p = handle_cardinal(p, flags);
	conv_x_intern(&p[0], flags, &count);
	free(p);
	return (count);
}
