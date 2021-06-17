/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:44:25 by josantos          #+#    #+#             */
/*   Updated: 2021/03/31 17:15:20 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*do_h(t_flags *flags, va_list args)
{
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa((short)va_arg(args, int)));
	if (flags->type == 'u')
	{
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned),
			"0123456789"));
	}
	if (flags->type == 'x')
	{
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned),
			"0123456789abcdef"));
	}
	if (flags->type == 'X')
	{
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned),
			"0123456789ABCDEF"));
	}
	return (NULL);
}

static char		*do_hh(t_flags *flags, va_list args)
{
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa((char)va_arg(args, int)));
	if (flags->type == 'u')
	{
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned),
			"0123456789"));
	}
	if (flags->type == 'x')
	{
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned),
			"0123456789abcdef"));
	}
	if (flags->type == 'X')
	{
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned),
			"0123456789ABCDEF"));
	}
	return (NULL);
}

static char		*do_l(t_flags *flags, va_list args)
{
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_llitoa((long)va_arg(args, long)));
	if (flags->type == 'u')
	{
		return (ft_litoa_base((unsigned long)va_arg(args, unsigned long),
				"0123456789"));
	}
	if (flags->type == 'x')
	{
		return (ft_litoa_base((unsigned long)va_arg(args, unsigned long),
				"0123456789abcdef"));
	}
	if (flags->type == 'X')
	{
		return (ft_litoa_base((unsigned long)va_arg(args, unsigned long),
				"0123456789ABCDEF"));
	}
	return (NULL);
}

static char		*do_ll(t_flags *flags, va_list args)
{
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_llitoa(va_arg(args, long long)));
	if (flags->type == 'u')
	{
		return (ft_llitoa_base((unsigned long long)va_arg(args, long long),
			"0123456789"));
	}
	if (flags->type == 'x')
	{
		return (ft_llitoa_base((unsigned long long)va_arg(args, long long),
			"0123456789abcdef"));
	}
	if (flags->type == 'X')
	{
		return (ft_llitoa_base((unsigned long long)va_arg(args, long long),
			"0123456789ABCDEF"));
	}
	return (NULL);
}

char			*arg_conversion(t_flags *flags, va_list args)
{
	if (flags->h)
		return (do_h(flags, args));
	else if (flags->hh)
		return (do_hh(flags, args));
	else if (flags->l)
		return (do_l(flags, args));
	else if (flags->ll)
		return (do_ll(flags, args));
	else if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (flags->type == 'u')
		return (ft_itoa_base(va_arg(args, unsigned), "0123456789"));
	else if (flags->type == 'x')
		return (ft_itoa_base(va_arg(args, unsigned), "0123456789abcdef"));
	else if (flags->type == 'X')
		return (ft_itoa_base(va_arg(args, unsigned), "0123456789ABCDEF"));
	else if (flags->type == 'p')
		return (ft_litoa_base(va_arg(args, unsigned long), "0123456789abcdef"));
	else
		return (NULL);
}
