/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:45:48 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 18:45:50 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	checa(const char c, va_list args, int *i, int *cont_letras)
{
	if (c == 'c')
		my_putchar(args, i, cont_letras);
	else if (c == 's')
		my_putstr(args, i, cont_letras);
	else if (c == 'd' || c == 'i')
		my_ft_putnbr(args, i, cont_letras);
	else if (c == 'u')
		my_putnbr_unsigned(args, i, cont_letras);
	else if (c == 'p')
		my_putnbr_pointer(args, i, cont_letras);
	else if (c == 'x')
		my_putnbr_base_minu(args, i, cont_letras);
	else if (c == 'X')
		my_putnbr_base_mais(args, i, cont_letras);
	else if (c == 'f')
		put_decimal(args, i, cont_letras);
}

int	ft_printf(const char *frase, ...)
{
	va_list	args;
	int		i;
	int		cont_letras;

	if (!frase)
		return (-1);
	va_start(args, frase);
	i = 0;
	cont_letras = 0;
	while (frase[i] != '\0')
	{
		if (frase[i] == '%' && frase[i + 1] == '%')
			my_put_perc(&i, &cont_letras);
		else if (frase[i] == '%')
			checa(frase[i + 1], args, &i, &cont_letras);
		else
		{
			write(1, &frase[i], 1);
			cont_letras++;
			i++;
		}
	}
	va_end(args);
	return (cont_letras);
}
