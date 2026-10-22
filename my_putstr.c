/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:18:21 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 19:18:23 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_putstr(va_list arg, int *iterador, int *c_letras)
{
	int		i;
	char	*str;

	(*iterador)++;
	i = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*c_letras = *c_letras + 6;
		(*iterador)++;
		return ;
	}
	while (str[i] != '\0')
	{
		i++;
		(*c_letras)++;
	}
	write(1, str, i);
	(*iterador)++;
}
