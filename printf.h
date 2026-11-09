/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:59:07 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/09 12:59:10 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr_base(unsigned long n, char *base);
int 	ft_putnbr_int(int n);
int		ft_printf(const char *s, ...);

#endif