/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:03:04 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:03:07 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsignint(unsigned int n)
{
	int	length;
	int	count;

	count = 0;
	length = 0;
	if (n >= 10)
	{
		length = ft_unsignint((n / 10));
		if (length == -1)
			return (-1);
		count += length;
	}
	length = ft_putchar((n % 10) + 48);
	if (length == -1)
		return (-1);
	count += length;
	return (count);
}
