/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:41 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/02/16 17:31:25 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char * string = "teste";
	(void)string;
	
	if(ft_printf("ola\n") == printf("ola\n"))
		write(1, "Success!\n", 10);
	else
		write(1, "Fail!\n", 7);

	/* ft_printf("%c\n",'d');
	printf("%c\n",'d');

	ft_printf("%s\n", "ola");
	printf("%s\n", "ola");

	ft_printf("%p\n", (void*)string);
	printf("%p\n", (void*)string);

	ft_printf("%d\n", 123);
	printf("%d\n", 123);

	ft_printf("%i\n", 123);
	printf("%i\n", 123);
	
	ft_printf("%u\n", -123);
	printf("%u\n", -123);

	ft_printf("%x\n", 123);
	printf("%x\n", 123);
	
	ft_printf("%X\n", 123);
	printf("%X\n", 123);

	ft_printf("%%\n");
	printf("%%\n"); */
}