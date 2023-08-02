/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:33:03 by tmazitov          #+#    #+#             */
/*   Updated: 2023/08/02 16:33:10 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == ch)
			return ((char *)str + counter);
		counter++;
	}
	if (str[counter] == ch)
		return ((char *)str + counter);
	return (0);
}
