/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:19:48 by josantos          #+#    #+#             */
/*   Updated: 2021/03/26 15:14:51 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*do_plus(char *p, t_flags *flags)
{
	char		*temp;

	if (flags->zero && !flags->point)
		flags->plus = 2;
	if (flags->plus == 1)
	{
		temp = p;
		p = ft_strjoin("+", p);
		free(temp);
	}
	return (p);
}

static char		*do_space(char *p, t_flags *flags)
{
	char *temp;

	if (flags->zero && !flags->point)
	{
		flags->space = 2;
		if (flags->min_width <= (int)ft_strlen(p))
			flags->space = 1;
	}
	if (flags->space == 1)
	{
		temp = p;
		p = ft_strjoin(" ", p);
		free(temp);
	}
	return (p);
}

static char		*handle_pos_intern(char *p, t_flags *flags)
{
	char		*temp;

	while (flags->precision > (int)ft_strlen(p))
	{
		temp = p;
		p = ft_strjoin("0", p);
		free(temp);
	}
	if (flags->plus)
		p = do_plus(p, flags);
	else if (flags->space)
		p = do_space(p, flags);
	return (p);
}

char			*handle_neg(t_flags *flags, char *p)
{
	char		*temp;

	temp = p;
	p = ft_substr(p, 1, (int)ft_strlen(p));
	free(temp);
	while (flags->precision > (int)ft_strlen(p))
	{
		temp = p;
		p = ft_strjoin("0", p);
		free(temp);
	}
	temp = p;
	p = ft_strjoin("-", p);
	free(temp);
	return (p);
}

char			*handle_pos(t_flags *flags, char *p)
{
	char		*temp;

	if (!ft_strncmp(p, "0", 1) && flags->point && !flags->precision)
	{
		temp = p;
		p = ft_strdup("");
		free(temp);
	}
	p = (handle_pos_intern(p, flags));
	return (p);
}
