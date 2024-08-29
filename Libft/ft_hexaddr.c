/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:00:34 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:00:37 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexadec(unsigned long n)
{
	int		length;
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	length = 0;
	if (n > 15)
	{
		length = ft_hexadec(n / 16);
		if (length == -1)
			return (-1);
		count += length;
	}
	length = write(1, &str[n % 16], 1);
	if (length == -1)
		return (-1);
	count += length;
	return (count);
}

int	ft_hexaddr(unsigned long n)
{
	int	length;
	int	count;

	count = 0;
	length = ft_putstr("0x");
	if (length == -1)
		return (-1);
	if (n == 0)
	{
		count = write(1, "0", 1);
		if (count == -1)
			return (-1);
		length += count;
	}
	else
	{
		count = ft_hexadec(n);
		if (count == -1)
			return (-1);
		length += count;
	}
	return (length);
}
