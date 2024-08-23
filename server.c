#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char *argv[])
{
	int pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr_fd("PID: ", 1); // print the pid with newline and wait for the messages from client
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, receiver);
		signal(SIGUSR2, receiver);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("ERROR", 2); // print error too few commands.
	return (0);
}