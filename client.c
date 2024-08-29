#include "minitalk.h"

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

void	error(int send_sig)
{
	ft_putendl_fd("ERROR..Kill got killed", 2);
	exit(1);
}

void    send_signals(int pid, char *s)
{
	int send_sig;
	int index;
	int i;
	int bit;
	
	i = 0;
	while(i <= strlen(s))
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
				error(send_sig);
			index--;
			usleep(500);
		}
		i++;
	}
}
int main(int argc, char *argv[])
{
	int pid;
	int i = 0;

	if (argc == 3)
	{
		if (ft_digit_str(argv[1]) != 1)
			return(ft_putendl_fd("ERROR..(Invalid PID)..There is a breach in protocol, the string should be Numeric", 2), 0);
		pid = ft_atoi(argv[1]);
		send_signals(pid, argv[2]);
	}
	else
		ft_putendl_fd("ERROR...The number of arguments should be 2", 2);
	return (0);
}