/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:08:10 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/09 13:14:54 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	dispatcher(const char *s, va_list *ap)
{
	char			c;
	unsigned long	p;

	if (*s == 'c')
	{
		c = va_arg(*ap, int);
		write(1, &c, 1);
		return (1);
	}
	if (*s == 's')
	{
		return (ft_putstr(va_arg(*ap, char *)));
	}
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr_int(va_arg(*ap, int)));
	if (*s == 'u')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789"));
	if (*s == 'x')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (*s == 'X')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	if (*s == 'p')	
	{
		p = va_arg(*ap, unsigned long);
		if (!p)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		write(1, "0x", 2);
		return (2 + ft_putnbr_base(p, "0123456789abcdef"));
	}
	if (*s == '%')
		write(1, "%", 1);
	return (1);
}

int ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += dispatcher(s + 1 + i, &ap);
			i++;
		}
		else
		{
			write(1, s + i, 1);
			len++;
		}
		if (s[i])
			i++;
	}
	va_end(ap);
	return (len);
}
