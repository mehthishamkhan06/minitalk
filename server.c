/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:44:50 by mohkhan           #+#    #+#             */
/*   Updated: 2024/09/02 16:44:52 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	receiver(int sig)
{
	static int	i;
	static char	c;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	else if (sig == SIGUSR2)
		c = c | 0;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("%s %d\n", "Welcome Aboard ...! PID IS:", pid);
		signal(SIGUSR1, receiver);
		signal(SIGUSR2, receiver);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Invalid ! Number Of Arguments : ./server", 2);
	return (0);
}
