/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:21:53 by josantos          #+#    #+#             */
/*   Updated: 2021/03/22 20:48:21 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags			init(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.min_width = 0;
	flags.point = 0;
	flags.precision = 0;
	flags.type = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.cardinal = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

int				check_obj(char *input, va_list args)
{
	int			count;
	int			a;
	t_flags		flags;

	if (!input)
		return (0);
	a = 0;
	count = 0;
	while (input[a])
	{
		flags = init();
		if (input[a] == '%' && input[a + 1])
		{
			a += set_params(&input[a], &flags, args);
			count += get_case(&input[a], &flags, args, &count);
		}
		else
			count += ft_putchar(input[a]);
		a++;
	}
	return (count);
}

int				ft_printf(const char *obj, ...)
{
	va_list		args;
	int			count;
	char		*input;

	if (!(input = ft_strdup(obj)))
		return (0);
	count = 0;
	va_start(args, obj);
	count = check_obj(input, args);
	va_end(args);
	free(input);
	return (count);
}
