/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:43 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/15 14:11:33 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client	g_client_info;

int	receive_byte(void)
{
	int	bit;
	int	byte;

	bit = (sizeof(char) * 8) - 1;
	byte = 0;
	while (bit >= 0)
	{
		while (!g_client_info.signal)
		{
			usleep(TIMEOUT);
			if (!g_client_info.signal)
				return (-1);
		}
		if (g_client_info.signal == SIGUSR1)
			byte |= 1 << bit;
		bit--;
		g_client_info.signal = 0;
		kill(g_client_info.pid, SIGUSR1);
	}
	return (byte);
}

bool	receive_signal(void *str, int size)
{
	int	i;
	int	check;

	ft_bzero(str, size);
	i = 0;
	while (i < size)
	{
		check = receive_byte();
		if (check == -1)
			return (false);
		((char *)str)[i] = check;
		i++;
	}
	return (true);
}

void	receive_print_message(int msg_len)
{
	char	*message;

	message = (char *)malloc(sizeof(char) * msg_len);
	if (!message)
	{
		ft_printf("Fail to malloc message.\n");
		return ;
	}
	message[msg_len - 1] = '\0';
	if (receive_signal(message, msg_len) == true)
	{
		ft_printf("Message length: %i\n", (msg_len - 1));
		ft_printf("Message:\n%s\n", message);
	}
	else
		ft_printf("Timeout: signal from client may missing.\n");
	free(message);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_client_info.pid)
		g_client_info.pid = info->si_pid;
	if (g_client_info.pid == info->si_pid)
		g_client_info.signal = signal;
}

int	main(void)
{
	struct sigaction	sa_server;
	int			msg_len;
	bool			receiving;

	sa_server.sa_sigaction = &signal_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&(sa_server.sa_mask));
	sigaddset(&(sa_server.sa_mask), SIGUSR1);
	sigaddset(&(sa_server.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR1, &sa_server, NULL) < 0
		|| sigaction(SIGUSR2, &sa_server, NULL) < 0)
		error_exit("Fail to handle signal.");
	ft_printf("Server PID: %i\n", getpid());
	while (1)
	{
		g_client_info.pid = 0;
		ft_printf("Waiting for message from client...\n");
		msg_len = 0;
		receiving = receive_signal(&msg_len, sizeof(msg_len));
		if (receiving == true && msg_len)
			receive_print_message(msg_len);
	}
	return (0);
}
