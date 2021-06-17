/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:22:19 by josantos          #+#    #+#             */
/*   Updated: 2021/03/31 17:08:50 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			star;
	int			min_width;
	int			point;
	int			precision;
	char		type;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			cardinal;
	int			space;
	int			plus;
}				t_flags;

int				ft_printf(const char *obj, ...);
int				check_obj(char *input, va_list args);
int				set_params(char *str, t_flags *flags, va_list args);
int				handle_width(t_flags *flags, int len);
int				get_case(char *str, t_flags *flags, va_list args, int *count);
int				handle_flags(char str, t_flags *flags);
int				handle_flags_bonus(char *str, t_flags *flags);
int				conv_percentage(t_flags *flags);
int				conv_c(t_flags *flags, va_list args);
int				conv_s(t_flags *flags, va_list args);
int				conv_p(t_flags *flags, va_list args);
int				conv_d_i(t_flags *flags, va_list args);
int				conv_u(t_flags *flags, va_list args);
int				conv_x(t_flags *flags, va_list args);
int				conv_n(t_flags *flags, va_list args, int *count);
char			*arg_conversion(t_flags *flags, va_list args);
char			*handle_neg(t_flags *flags, char *p);
char			*handle_pos(t_flags *flags, char *p);

#endif
