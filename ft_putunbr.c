/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:45:51 by tmazitov          #+#    #+#             */
/*   Updated: 2023/07/17 15:29:26 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unbr(unsigned int num)
{
	int	result;

	result = 0;
	if (num / 10 > 0)
		result += print_unbr(num / 10);
	result += ft_putchar('0' + num % 10);
	return (result);
}

int	ft_putunbr(int num)
{
	if (num >= 0)
		return (ft_putnbr(num));
	else 
		return (print_unbr(4294967296 + num));
}
