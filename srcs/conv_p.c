/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:58:45 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:12:44 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_zero(t_flags *flags, int *count, char *p)
{
	char	*temp;

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
	temp = p;
	p = ft_strjoin("0x", p);
	free(temp);
	return (p);
}

int			conv_p(t_flags *flags, va_list args)
{
	int		count;
	char	*p;

	count = 0;
	p = arg_conversion(flags, args);
	p = handle_zero(flags, &count, p);
	if (p[0] == '-')
		p = handle_neg(flags, p);
	else
		p = handle_pos(flags, p);
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
