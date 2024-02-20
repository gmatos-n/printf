/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:23:00 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/02/20 18:37:18 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long long int nbr, char *base, int base_count)
{
	unsigned int	count;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr / base_count > 0)
		count += ft_putnbr_base((nbr / base_count), base, base_count);
	write(1, &base[nbr % base_count], 1);
	count++;
	return (count);
}

int	ft_putnbr_ptr(unsigned long long nbr, char *base, int base_count,
		int prefix)
{
	unsigned int	count;

	count = 0;
	if (!nbr && prefix == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (prefix == 0)
	{
		ft_putstr("0x");
		count += 2;
	}
	if (nbr / base_count > 0)
		count += ft_putnbr_ptr((nbr / base_count), base, base_count, 1);
	write(1, &base[nbr % base_count], 1);
	count++;
	return (count);
}

int	print_format(char format, va_list args)
{
	int	c;

	if (format == '%')
		return (write(1, "%%", 1));
	else if (format == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 10));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				16));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				16));
	else if (format == 'p')
		return (ft_putnbr_ptr(va_arg(args, long int), "0123456789abcdef",
				16, 0));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
		else
		{
			count += print_format(str[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
