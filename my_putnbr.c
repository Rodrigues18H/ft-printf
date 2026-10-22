/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:43:34 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 21:43:35 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	my_putnbr(int n, int *c_letras)
{
	char	str;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*c_letras = *c_letras + 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		(*c_letras)++;
	}
	if (n >= 10)
		my_putnbr(n / 10, c_letras);
	str = (n % 10) + '0';
	write(1, &str, 1);
	(*c_letras)++;
}

void	my_ft_putnbr(va_list arg, int *it, int *len_letras)
{
	int	num;

	(*it)++;
	num = va_arg(arg, int);
	my_putnbr(num, len_letras);
	(*it)++;
}
