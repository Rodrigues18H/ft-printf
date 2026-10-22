/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_putnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 09:31:13 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/25 09:31:14 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	my_ft_putnbr_base(unsigned int n, char *base, int *c_letras)
{
	char	caracter;

	if (n >= 16)
		my_ft_putnbr_base((n / 16), base, c_letras);
	caracter = base[n % 16];
	write(1, &caracter, 1);
	(*c_letras)++;
}

void	my_putnbr_base_minu(va_list arg, int *it, int *len_letras)
{
	unsigned int	num;

	(*it)++;
	num = va_arg(arg, unsigned int);
	my_ft_putnbr_base(num, "0123456789abcdef", len_letras);
	(*it)++;
}

void	my_putnbr_base_mais(va_list arg, int *it, int *len_letras)
{
	unsigned int	num;

	(*it)++;
	num = va_arg(arg, unsigned int);
	my_ft_putnbr_base(num, "0123456789ABCDEF", len_letras);
	(*it)++;
}
