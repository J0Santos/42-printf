/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:29:25 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:59:22 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0' && !flags->minus && !flags->point)
		flags->zero = 1;
	else if (c == '.')
		flags->point = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '#')
		flags->cardinal = 1;
	return (0);
}

int		handle_flags_bonus(char *str, t_flags *flags)
{
	int	a;

	a = 0;
	if (str[a] == 'h' && str[a + 1] != 'h')
		flags->h = 1;
	else if (str[a] == 'h' && str[a + 1] == 'h')
	{
		flags->hh = 1;
		a++;
	}
	if (str[a] == 'l' && str[a + 1] != 'l')
		flags->l = 1;
	else if (str[a] == 'l' && str[a + 1] == 'l')
	{
		flags->ll = 1;
		a++;
	}
	return (a);
}
