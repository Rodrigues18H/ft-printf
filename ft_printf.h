/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:46:31 by rojamba           #+#    #+#             */
/*   Updated: 2026/08/24 18:46:32 by rojamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *frase, ...);
void	my_putchar(va_list arg, int *iterador, int *c_letras);
void	my_putstr(va_list arg, int *iterador, int *c_letras);
void	my_ft_putnbr(va_list arg, int *it, int *len_letras);
void	my_putnbr_unsigned(va_list arg, int *it, int *len_letras);
void	my_putnbr_pointer(va_list arg, int *it, int *len_letras);
void	my_putnbr_base_minu(va_list arg, int *it, int *c_letras);
void	my_putnbr_base_mais(va_list arg, int *it, int *len_letras);
void	my_put_perc(int *iterador, int *c_letras);
void    put_decimal(va_list arg, int *it, int *c_letras);

#endif
