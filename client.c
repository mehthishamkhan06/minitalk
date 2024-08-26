#include <unistd.h>
#include <stdio.h>
#include	<ctype.h>
#include <signal.h>
#include "Libft/libft.h"


//SIGUSER1: represents bit value 1
//SIGUSER2: represents bit value 0
int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void    send_signals(int pid, char *s)
{
	int send_sig;
	int index;
	int i;
	int bit;
	
	i = 0;
	bit = 0;
	send_sig = 0;
	while(s[i])
	{
		index = 7;
		while(index >= 0)
		{
			bit = s[i] >> index & 1;
			if (bit == 1)
				send_sig = kill(pid, SIGUSR1);
			else
				send_sig = kill(pid, SIGUSR2);
			if (send_sig == -1)
			{
				ft_putendl_fd("ERROR..Kill got killed", 2);
				exit(1);
			}
			index--;
			usleep(500);
		}
		i++;
	}
}
void    send_null_signals(int pid, char c)
{
	int send_sig;
	int index;
	int i;
	int bit;
	
	i = 0;
	bit = 0;
	send_sig = 0;
	index = 7;
	while(index >= 0)
	{
		bit = c >> index & 1;
		if (bit == 1)
			send_sig = kill(pid, SIGUSR1);
		else
			send_sig = kill(pid, SIGUSR2);
		if (send_sig == -1)
		{
			ft_putendl_fd("ERROR..Kill got killed", 2);
			exit(1);
		}
		index--;
		usleep(500);
	}
	i++;
}
int main(int argc, char *argv[])
{
	int pid;
	int i = 0;

	if (argc == 3)
	{
		if (is_digit_str(argv[1]) != 1) //replace is digit with your own func as ft_isdigit doesnt check for complete string.
			//print error
			return(ft_putendl_fd("ERROR..(Invalid PID)..There is a breach in protocol, the string should be Numeric", 2), 0);// for safety..)
		// extract pid to readable using atoi
		pid = ft_atoi(argv[1]);
		send_signals(pid, argv[2]); //create a send signals functions
		send_null_signal(pid, '\0');
	}
	else
		//print error message
		ft_putendl_fd("ERROR...The number of arguments should be 2", 2);
	return (0);
}