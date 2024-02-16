/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:09:23 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/02/16 18:53:32 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(char format, va_list args)
{
    if(format == '%')
        return(ft_putchar('%'));
    else if(format == 'c')
        return(ft_putchar(format));
    else if(format == 's')
        return(ft_putstr(va_arg(args, char *)));
    else if(format == 'd' || format == 'i')
        return(ft_putnbr_base(va_arg(args, int), "10"));
    else if(format == 'u')
        return(ft_putnbr_base(va_arg(args, unsigned int), "10"));
    else if(format == 'x')
        return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
    else if(format == 'X')
        return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
    else if(format == 'p')
        return();
    else
        return(0);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
    int i = 0;
    int count = 0;
    va_start(args, str);

    while(str[i])
    {
        if(str[i] != '%')
        {
            write(1, &str[i], 1);
            i++;
            count++;
        }
        else
        {
            count+=print_format(str[i+1], args);
            i+=2;
        }
    }
	va_end(args);
    return(count);
}
