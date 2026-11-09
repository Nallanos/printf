#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr_base(unsigned long n, char *base);
int 	ft_putnbr_int(int n);

#endif