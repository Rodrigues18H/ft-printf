/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:45:24 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 18:45:28 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_putchar(va_list arg, int *iterador, int *c_letras)
{
	char	c;

	(*iterador)++;
	c = va_arg(arg, int);
	write(1, &c, 1);
	(*c_letras)++;
	(*iterador)++;
}

void	my_put_perc(int *iterador, int *c_letras)
{
	char	c;

	(*iterador)++;
	c = '%';
	write(1, &c, 1);
	(*c_letras)++;
	(*iterador)++;
}
