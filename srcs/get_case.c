/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:58:45 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:14:22 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_case(char *str, t_flags *flags, va_list args, int *count)
{
	int	a;

	a = 0;
	if (str[a] == 'c')
		return (conv_c(flags, args));
	else if (str[a] == 's')
		return (conv_s(flags, args));
	else if (str[a] == 'p')
		return (conv_p(flags, args));
	else if (str[a] == 'd' || str[a] == 'i')
		return (conv_d_i(flags, args));
	else if (str[a] == 'u')
		return (conv_u(flags, args));
	else if (str[a] == 'x' || str[a] == 'X')
		return (conv_x(flags, args));
	else if (str[a] == '%')
		return (conv_percentage(flags));
	else if (str[a] == 'n')
		return (conv_n(flags, args, count));
	return (0);
}
