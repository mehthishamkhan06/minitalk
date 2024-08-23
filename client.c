#include <unistd.h>
#include <stdio.h>
#include	<ctype.h>
#include <signal.h>


//SIGUSER1: represents bit value 1
//SIGUSER2: represents bit value 0
int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!ft_isdigit[i])
			return (0);
		i++;
	}
	return (1);
}

void    send_signals(int pid, char c)
{
	int a;
	int b;
	
	a = 0;
	b = 7;
	while(b-- >= 0)
	{
		if ((c >> i && 1) == 0)
		{
			j = kill(pid, SIGUSR2);
			if (j == -1)
				return(ft_putendl_fd("ERROR", 2),exit(1),0);  
		}
		else
		{
			j = kill(pid, SIGUSR1);
			if (j == -1)
				return(ft_putendl_fd("ERROR", 2),exit(1),0);
		}
		usleep(150);
	}
}
int main(int argc, char *argv[])
{
	int pid;
	int i = 0;

	if (argc == 3)
	{
		if (ft_isdigit(argv[1]) != 1) //replace is digit with your own func as ft_isdigit doesnt check for complete string.
			//print error
			return(ft_putendl_fd("ERROR", 2), 0);// for safety..)
		// extract pid to readable using atoi
		pid = ft_atoi(argv[1]);
		while(argv[2][i])
			send_signals(pid, argv[2][i++]); //create a send signals functions
		send_signals(pid, '\0');
	}
	else
		//print error message
		ft_putendl_fd("ERROR", 2);
	return (0);
}