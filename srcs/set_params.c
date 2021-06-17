/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:15:26 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 16:05:02 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_star(t_flags *flags, int arg)
{
	if (!flags->point)
		flags->min_width = arg;
	else
		flags->precision = arg;
	flags->star += 1;
}

static int		width_handle(char *str, t_flags *flags)
{
	int		a;

	a = 0;
	if (!flags->point)
		flags->min_width = ft_atoi(str);
	else
		flags->precision = ft_atoi(str);
	while (ft_isdigit(str[a]))
		a++;
	return (--a);
}

static void		minus_handle(t_flags *flags)
{
	if (flags->min_width < 0)
	{
		flags->minus = 1;
		flags->min_width *= -1;
	}
	if (flags->minus && flags->zero)
		flags->zero = 0;
}

int				set_params(char *str, t_flags *flags, va_list args)
{
	int			a;

	a = -1;
	while (str[++a])
	{
		if (str[a] == '-' || str[a] == '0' || str[a] == '.'
				|| str[a] == ' ' || str[a] == '+' || str[a] == '#')
			handle_flags(str[a], flags);
		else if (str[a] == 'h' || str[a] == 'l')
			a += handle_flags_bonus(&str[a], flags);
		else if (str[a] == '*')
			handle_star(flags, va_arg(args, int));
		else if (ft_isdigit(str[a]))
			a += width_handle(&str[a], flags);
		else if (ft_strchr("cspdiuxXnfge%", str[a]) && a != 0)
		{
			flags->type = str[a];
			break ;
		}
		else if (ft_isalpha(str[a]))
			break ;
	}
	minus_handle(flags);
	return (flags->type == 0 ? 0 : a);
}
