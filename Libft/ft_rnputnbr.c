/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rnputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:02:37 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:13:19 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(int length, int *count)
{
	length = write(1, "-", 1);
	if (length == -1)
		return (-1);
	*count += length;
	return (0);
}

int	ft_rnputnbr(int n)
{
	int	length;
	int	count;

	count = 0;
	length = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (check(length, &count) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		length = ft_rnputnbr((n / 10));
		if (length == -1)
			return (-1);
		count += length;
	}
	length = ft_putchar((n % 10) + '0');
	if (length == -1)
		return (-1);
	count++;
	return (count);
}
