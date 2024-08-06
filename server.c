#include "minitalk.h"

/*
SIGUSR1 = 1
SIGUSR2 = 0
*/
void handle_signal(int signal)
{
    static int c = 0x00;
    static int bits = 0;

    if (signal == SIGUSR1)
        c |= 0x01 << bits;
    bits++;
    if (bits == 8)
    {
        write(1, &c, 1);
        c = 0x00;
        bits = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;
    //check argc, only 1
    (void)argv;
    if (argc != 1)
    {
        ft_printf("Wrong Format.\n");
        ft_printf("Enter: ./server\n");
        return (0);
    }
    pid = getpid();
    ft_printf("Server PID: %i\n", pid);
    //handle signal
    while (argc == 1)
    {
        signal(SIGUSR1, handle_signal);
        signal(SIGUSR2, handle_signal);
        pause();
    }
    return (0);
}
