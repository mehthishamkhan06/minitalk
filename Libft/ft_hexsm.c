/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexsm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:01:00 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:12:54 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexsm(unsigned int n)
{
	int		length;
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	length = 0;
	if (n > 15)
	{
		length = ft_hexsm(n / 16);
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
