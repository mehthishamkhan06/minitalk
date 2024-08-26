/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:50 by mohkhan           #+#    #+#             */
/*   Updated: 2024/06/24 13:19:53 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr(int nb, int fd)
{
	char	a;

	if (nb >= 10)
	{
		putnbr(nb / 10, fd);
		a = nb % 10 + 48;
		write(fd, &a, 1);
	}
	else
	{
		a = nb + 48;
		write(fd, &a, 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		putnbr(-1 * nb, fd);
	}
	else
		putnbr(nb, fd);
}
