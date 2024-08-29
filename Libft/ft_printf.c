/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:01:13 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/11 15:11:34 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkformat(char c, va_list lst)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		len += ft_putstr(va_arg(lst, char *));
	else if (c == 'p')
		len += ft_hexaddr(va_arg(lst, unsigned long));
	else if (c == 'd' || c == 'i')
		len += ft_rnputnbr(va_arg(lst, int));
	else if (c == 'u')
		len += ft_unsignint(va_arg(lst, unsigned int));
	else if (c == 'x')
		len += ft_hexsm(va_arg(lst, unsigned int));
	else if (c == 'X')
		len += ft_hexcap(va_arg(lst, unsigned int));
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;
	int		count;

	i = 0;
	len = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
			count = ft_checkformat(str[++i], lst);
		else
			count = ft_putchar(str[i]);
		if (count == -1)
			return (-1);
		len += count;
		i++;
	}
	va_end(lst);
	return (len);
}
