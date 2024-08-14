/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:43 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/12 11:53:20 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client info_client;

int receive_byte(unsigned char *c)
{
	int bit;
	
	bit = (sizeof(char) * 8) - 1;
	
	while (bit >= 0)
	{
	
		while (!info_client.signal)
		{
			usleep(TIMEOUT);
			if (!info_client.signal)
				return (1);
		}
		
		if (info_client.signal == SIGUSR1)
		{
			*c |= 1 << bit;
			//ft_printf("%c\n", c[0]);
		}
		bit--;
		info_client.signal = 0;
		kill(info_client.pid, SIGUSR1);
	}
	return (0);
}

void *receive_signal(void *str, int size)
{
	unsigned char *ptr;
	int err;

	ft_bzero(str, size);
	ptr = (unsigned char *)str;
	while (size--)
	{
		err = receive_byte(ptr++);
		//ft_printf("str %s\n", (char *)str);
		if (err)
			return (NULL);
	}
	return (str);
}

void receive_print_message(int len)
{
	char *msg;

	msg = malloc(len + 1);
	
	if (msg)
	{
		msg[len] = '\0';
		
		if (receive_signal(msg, len))
		{
			//ft_printf("a\n");
			ft_printf("%s\n", msg);
		}
		else
			ft_printf("Timeout\n");
		free(msg);
	}
	else
		ft_printf("ERROR\n");
}


void signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (!info_client.pid)
		info_client.pid = info->si_pid;
	if (info_client.pid == info->si_pid)
		info_client.signal = signal;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_server;
	int len;
	void *ret;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong Format. Enter: [./server]\n");
		exit(1);
	}

	sigemptyset(&(sa_server.sa_mask));
	sigaddset(&(sa_server.sa_mask), SIGUSR1);
	sigaddset(&(sa_server.sa_mask), SIGUSR2);
	sa_server.sa_sigaction = &signal_handler;
	sa_server.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGUSR1, &sa_server, NULL) < 0
		|| sigaction(SIGUSR2, &sa_server, NULL) < 0)
	{
		ft_printf("Fail to handle signal in server.");
		exit(EXIT_FAILURE);
	}

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);

	while (1)
	{
		info_client.pid = 0;
		ft_printf("waiting...\n");
		
		len = 0;
		ret = receive_signal(&len, sizeof(len));
		ft_printf("len: %i\n", len);
		if (ret && len)
			receive_print_message(len);
	}
	return (0);
}
