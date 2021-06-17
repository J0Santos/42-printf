/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:48:02 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:12:07 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_n(t_flags *flags, va_list args, int *count)
{
	if (flags->h)
		*(short *)va_arg(args, int *) = *count;
	else if (flags->hh)
		*(signed char *)va_arg(args, signed char *) = *count;
	else if (flags->l)
		*(long *)va_arg(args, long *) = *count;
	else if (flags->ll)
		*(long long *)va_arg(args, long long *) = *count;
	else
		*va_arg(args, int *) = *count;
	return (0);
}
