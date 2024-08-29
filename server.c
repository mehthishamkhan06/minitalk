#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "Libft/libft.h"

void	receiver(int sig)
{
	static int i = 0;
	static char	c = 0;

	c = c << 1;
	if(sig == SIGUSR1)
		c = c | 1;
	else if (sig == SIGUSR2)
		c = c | 0;
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
			write(2, "error404", 5);	
		ft_putchar_fd(c, 1);
		c = 0;
	}
}
int main(int argc, char *argv[])
{
	int pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("%s %d\n", "PID IS:", pid); //replace printf with your printf
		signal(SIGUSR1, receiver);
		signal(SIGUSR2, receiver);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("ERROR...Please check the ", 2);
	return (0);
}