/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:44:33 by mohkhan           #+#    #+#             */
/*   Updated: 2024/09/02 16:44:35 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_length;

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	acknowledge(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Congratulations....! Server received %d characters", g_length);
	exit (0);	
}

void	ft_error(int send_sig)
{
	if (send_sig == -1)
	{
		ft_putendl_fd("ERROR..Invalid PID. KILL got killed", 2);
		exit (1);
	}
}

void	send_signals(int pid, char *s)
{
	int	send_sig;
	int	index;
	int	i;
	int	bit;

	i = 0;
	while (i <= ft_strlen(s))
	{
		index = 7;
		while (index >= 0)
		{
			bit = s[i] >> index & 1;
			if (bit == 1)
				send_sig = kill(pid, SIGUSR1);
			else
				send_sig = kill(pid, SIGUSR2);
			if (send_sig == -1)
				ft_error(send_sig);
			index--;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (is_digit_str(argv[1]) != 1)
			return (ft_putendl_fd("ERROR..(Invalid PID)", 2), 0);
		pid = ft_atoi(argv[1]);
		send_signals(pid, argv[2]);
		g_length = ft_strlen(argv[2]);
		signal(SIGUSR1, acknowledge);
		while(1)
			pause();
	}
	else
		ft_putendl_fd("ERROR...The number of arguments should be 3", 2);
	return (0);
}
