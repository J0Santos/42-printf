/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:58:45 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:13:35 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*handle_precision(t_flags *flags, char *p)
{
	if (!flags->precision && flags->point)
		p = ft_strdup("");
	else if (flags->precision < (int)ft_strlen(p) && flags->point)
		p = ft_substr(p, 0, flags->precision);
	else
		p = ft_strdup(p);
	return (p);
}

int				conv_s(t_flags *flags, va_list args)
{
	int			count;
	char		*p;

	count = 0;
	p = va_arg(args, char *);
	if (!p)
		p = "(null)";
	p = handle_precision(flags, p);
	if (flags->minus && flags->min_width > (int)ft_strlen(p))
	{
		count += ft_putstr(p);
		count += handle_width(flags, (int)ft_strlen(p));
	}
	else if (flags->min_width > (int)ft_strlen(p))
	{
		count += handle_width(flags, (int)ft_strlen(p));
		count += ft_putstr(p);
	}
	else
		count += ft_putstr(p);
	free(p);
	return (count);
}
