/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:45:49 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/08 12:58:59 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ack_handler(int signal)
{
	(void)signal;
}

//need kill() < 0 checker?
void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		bit--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\n');
}

//need sigaction() < 0 checker?
int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_client;

	if (argc != 3)
	{
		ft_printf("Error: Wrong For00mat.\n");
		ft_printf("Enter: ./client <PID> <string>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
	{
		ft_printf("Error: Invalid PID.\n");
		return (1);
	}
	sigemptyset(&sa_client.sa_mask);
	sa_client.sa_flags = SA_RESTART;
	sa_client.sa_handler = ack_handler;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	send_message(pid, argv[2]);
	return (0);
}
