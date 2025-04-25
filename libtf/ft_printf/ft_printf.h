/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 10:59:52 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-19 10:59:52 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);

int				ft_putchar(char c);

int				ft_putnbr(int n);

int				ft_putstr(char *s);

int				ft_printf_hex(int num, int isx);

int				ft_printf_ptr(long num);

int unsigned	ft_putnbr_unsigned(unsigned int num);

#endif
