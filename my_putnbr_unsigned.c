/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:43:56 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 22:43:57 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	putnbr_unsigned(unsigned int n, int *c_letras)
{
	char	str;

	if (n >= 10)
		putnbr_unsigned(n / 10, c_letras);
	str = (n % 10) + '0';
	write(1, &str, 1);
	(*c_letras)++;
}

void	my_putnbr_unsigned(va_list arg, int *it, int *len_letras)
{
	unsigned int	num;

	(*it)++;
	num = va_arg(arg, unsigned int);
	putnbr_unsigned(num, len_letras);
	(*it)++;
}
