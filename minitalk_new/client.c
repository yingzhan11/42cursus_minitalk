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
	//ft_printf("ack\n");
}

//need kill() < 0 checker?
/*void	send_byte(int pid, char c)
{
	int	bit;

	bit = (sizeof(char) * 8) - 1;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("Fail to kill SIGUSR1 from clinet to server.");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Fail to kill SIGUSR2 from clinet to server.");
				exit(EXIT_FAILURE);
			}
		}
		bit--;
		pause();
	}
}*/

/*void	send_message(int pid, void *str)
{
	int	i;
	char	*send;

	send = (char *)str;
	i = 0;
	while (send[i] != '\0')
	{
		send_byte(pid, send[i]);
		i++;
	}
	send_byte(pid, '\0');
}*/

/*void send_length(pid_t pid, int len)
{
	//int n;
	//char bit;

	n = (sizeof(int) * 8) - 1;
	while (n >= 0)
	{
		bit = (len >> n) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		n--;
	}
	char *str_len;

	str_len = ft_itoa(len);
	//ft_printf("i %i\n", len);
	//ft_printf("str %s\n", str_len);
	send_message(pid, str_len);
}*/

void	send_byte(int pid, unsigned char c)
{
	int	bit;

	bit = (sizeof(char) * 8) - 1;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("Fail to kill SIGUSR1 from clinet to server.");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Fail to kill SIGUSR2 from clinet to server.");
				exit(EXIT_FAILURE);
			}
		}
		usleep(500);
		bit--;
	}
}

void send(pid_t pid, void *str, int len)
{
	unsigned char *ptr;

	ptr = (unsigned char *) str;
	while (len--)
	{
		send_byte(pid, *ptr++);
	}
}

//need sigaction() < 0 checker?
int	main(int argc, char **argv)
{
	int					pid;
	int len;
	//struct sigaction	sa_client;

	if (argc != 3)
	{
		ft_printf("Error: Wrong Format. Enter: [./client <PID> <string>]\n");
		exit(EXIT_FAILURE);
	}

	signal(SIGUSR1, &ack_handler);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]) + 1;
	
	if (kill(pid, 0) < 0)
	{
		ft_printf("Error: Invalid PID.");
		exit(EXIT_FAILURE);
	}
	send(pid, &len, sizeof(len));
	send(pid, argv[2], len);
	//send_length(pid, len);
	//send_message(pid, argv[2]);
	ft_printf("DONE\n");
	return (EXIT_SUCCESS);
}
