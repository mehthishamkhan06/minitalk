#include <unistd.h>
#include <stdio.h>
#include	<ctype.h>


int main(int argc, char *argv[])
{
    int pid;
    int i = 0;

    if (argc == 3)
    {
        if (is_alpha(argv[1]) != 1)
            //print error
        // extract pid to readable using atoi
        pid = ft_atoi(argv[1]);
        //converrt the pid to signals so the the server can understand

    }
    else
        //print error message
}