/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:08:27 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 17:58:40 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (dst == '\0' && src == '\0')
		return (0);
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dst);
}
