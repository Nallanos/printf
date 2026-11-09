/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:59:07 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/09 12:59:10 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long p);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putnbr_int(int n);
int	ft_strlen(const char *s);

#endif
