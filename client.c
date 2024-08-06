#include "minitalk.h"

void send_signal(int pid, char c)
{
    int bits;

    bits = 0;
    while (bits < 8)
    {
        if ((c & (0x01 << bits)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        bits++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    //check argc
    if (argc != 3)
    {
        ft_printf("Wrong For00mat.\n");
        ft_printf("Enter: ./client <PID> <string>\n");
        return (0);
    }
    else
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            send_signal(pid, argv[2][i]);
            i++;
        }
        send_signal(pid, '\n');
    }
    return (0);
}