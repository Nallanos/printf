/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:19:07 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/09 13:04:33 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, ft_strlen(s));
	return (len);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				len;
	unsigned long	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		len = ft_putnbr_base(n / base_len, base);
	write(1, &base[n % base_len], 1);
	return (len + 1);
}

int	ft_putnbr_int(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		return (ft_putnbr_base((unsigned long)n, "0123456789") + 1);
	}
	return (ft_putnbr_base((unsigned long)n, "0123456789"));
}
