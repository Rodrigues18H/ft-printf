/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 08:26:41 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/25 08:26:42 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	uintptr_t	conta(char *ba)
{
	uintptr_t	i;

	i = 0;
	while (ba[i] != '\0')
		i++;
	return (i);
}

static	void	my_putnbr_h(uintptr_t n, char *base, int *c_letras)
{
	char		str;
	uintptr_t	base_cont;

	base_cont = conta(base);
	if (n >= 16)
		my_putnbr_h((n / base_cont), base, c_letras);
	str = base[n % base_cont];
	write(1, &str, 1);
	(*c_letras)++;
}

void	my_putnbr_pointer(va_list arg, int *it, int *len_letras)
{
	void		*point;
	uintptr_t	end;

	(*it)++;
	point = va_arg(arg, void *);
	if (point == NULL)
	{
		write(1, "(nil)", 5);
		*len_letras = *len_letras + 5;
		(*it)++;
		return ;
	}
	end = (uintptr_t)point;
	write(1, "0x", 2);
	*len_letras = *len_letras + 2;
	my_putnbr_h(end, "0123456789abcdef", len_letras);
	(*it)++;
}
