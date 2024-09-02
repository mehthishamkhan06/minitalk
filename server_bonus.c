/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:44:58 by mohkhan           #+#    #+#             */
/*   Updated: 2024/09/02 16:45:00 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "Libft/libft.h"

void	receiver(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	else if (sig == SIGUSR2)
		c = c | 0;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
		{
			usleep(300);
			kill(siginfo->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("%s %d\n", "PID IS:", pid);
		sa1.sa_flags = SA_SIGINFO;
		sa1.sa_sigaction = receiver;
		sigemptyset(&sa1.sa_mask);
		sa2.sa_flags = SA_SIGINFO;
		sa2.sa_sigaction = receiver;
		sigemptyset(&sa2.sa_mask);
		sigaction(SIGUSR1, &sa1, NULL);
		sigaction(SIGUSR2, &sa2, NULL);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Invalid ! Number Of Arguments : ./server", 2);
	return (0);
}
