/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:43 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/08 12:55:05 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
SIGUSR1 = 1
SIGUSR2 = 0
*/
void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	bit = 7;

	usleep(100);
	(void)context;
	if (signal == SIGUSR1)
		c |= 1 << bit;
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		c = 0;
		bit = 7;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_server;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong Format.\n");
		ft_printf("Enter: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_sigaction = signal_handler;
	sa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	while (argc == 1)
		pause();
	return (0);
}
