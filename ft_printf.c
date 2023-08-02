/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:15:18 by tmazitov          #+#    #+#             */
/*   Updated: 2023/08/02 15:54:24 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_print_type(const char *format_str, va_list args)
{
	if (*format_str == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format_str == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format_str == 'p')
		return (ft_puthex(va_arg(args, unsigned long long)));
	if (*format_str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (*format_str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*format_str == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (*format_str == 'x')
		return (ft_print_low_hex(va_arg(args, unsigned int)));
	if (*format_str == 'X')
		return (ft_print_up_hex(va_arg(args, unsigned int)));
	if (*format_str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format_str, ...)
{
	int		counter;
	int		chars;
	int		t_print_result;
	va_list	args;

	if (!format_str)
		return (0);
	counter = 0;
	chars = 0;
	va_start(args, format_str);
	while (format_str[counter])
	{
		if (format_str[counter] == '%' && format_str[counter + 1])
		{
			t_print_result = ft_print_type(&format_str[counter + 1], args);
			counter += 2;
			chars += t_print_result;
			continue ;
		}
		ft_putchar(format_str[counter]);
		chars++;
		counter++;
	}
	va_end(args);
	return (chars);
}

/*
#include <stdio.h>
#include <limits.h>

int main()
{
	// %c
	ft_printf("TEST c:\t%c\t", '$'); 
	printf("	orig: %c\n", '$');
	// %s
	ft_printf("TEST s:\t%s\t", "hello");
	printf("	orig: %s\n", "hello");
	// %p
	int a = 5;
	int *b = &a;
	ft_printf("TEST p:\t%p\t", b);
	printf("	orig: %p\n", b);
	// %d
	ft_printf("TEST d:\t%d\t", 52);
	printf("	orig: %d\n", 52);
	// %i
	ft_printf("TEST i:\t%i\t", Ox);
	printf("	orig: %i\n", 0b01110);
	// %u
	ft_printf("TEST u:\t%u\t", 1);
	printf("	orig: %u\n", 1);
	%x
	ft_printf("TEST x:\t%x\t", LONG_MAX);
	printf("	orig: %x\n", LONG_MAX);
	// %X
	ft_printf("TEST s:\t%X\t",90567890);
	printf("	orig: %X\n", 90567890);
}*/