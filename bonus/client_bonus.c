/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:53:16 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/16 14:53:20 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_ack;

void	ack_handler(int signal)
{
	g_ack = signal;
}

/*
Function to send one signal(bit) to receiver.
After send a signal, waiting for an ack signal from receiver,
if waiting-time is longer than 10 secs, it will show timeout error
and exit the program. 
*/
int	send_byte(int pid, char c)
{
	int	bit;

	bit = (sizeof(char) * 8) - 1;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				return (-1);
		}
		while (!g_ack)
		{
			usleep(TIMEOUT);
			if (!g_ack)
				error_exit("Time out: ack signal from server may missing.");
		}
		g_ack = 0;
		bit--;
	}
	return (0);
}

/*Fuction to send msg to receiver*/
void	send(pid_t pid, void *str, int msg_len)
{
	int		i;
	char	byte_to_send;

	i = 0;
	while (i < msg_len)
	{
		byte_to_send = ((char *)str)[i];
		if (send_byte(pid, byte_to_send) == -1)
			error_exit("Fail to send signal to server.");
		i++;
	}
}

/*Get msg len and send it to receiver, then send the msg.*/
int	main(int argc, char **argv)
{
	int	pid;
	int	msg_len;

	if (argc != 3)
		error_exit("Error: Wrong Format. Enter: [./client <PID> <string>]");
	signal(SIGUSR1, &ack_handler);
	signal(SIGUSR2, &ack_handler);
	pid = ft_atoi(argv[1]);
	msg_len = ft_strlen(argv[2]) + 1;
	ft_printf("[Message length: %i]\n", (msg_len - 1));
	if (kill(pid, 0) < 0)
		error_exit("Error: Invalid PID.");
	send(pid, &msg_len, sizeof(msg_len));
	send(pid, argv[2], msg_len);
	ft_printf("Finish sending.\n");
	while (g_ack != SIGUSR2)
	{
		usleep(TIMEOUT);
		if (!g_ack)
			error_exit("Time out: ack signal from server may missing.");
	}
	ft_printf("Server already receive message.\n");
	return (0);
}
