/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:00:46 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:11:47 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexcap(unsigned int n)
{
	int		length;
	char	*str;
	int		count;

	count = 0;
	length = 0;
	str = "0123456789ABCDEF";
	if (n >= 16)
	{
		length = ft_hexcap((n / 16));
		if (length == -1)
			return (-1);
		count += length;
	}
	length = ft_putchar(str[n % 16]);
	if (length == -1)
		return (-1);
	count += length;
	return (count);
}
