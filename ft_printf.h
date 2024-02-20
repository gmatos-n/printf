/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:45 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/02/20 18:19:51 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *str);
int	ft_putnbr_base(long long int nbr, char *base, int base_count);
int	ft_putnbr_ptr(unsigned long long nbr, char *base, int base_count,
		int prefix);
int	print_format(char format, va_list args);
int	ft_printf(const char *str, ...);

#endif