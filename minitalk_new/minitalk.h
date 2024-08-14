/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:51:48 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/08 12:52:34 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

# define TIMEOUT 10000000

typedef struct s_server
{
    char *str_len; //data
    int len;
    int get_len; //flag
    char *str;
} t_server;

typedef struct s_client
{
	volatile sig_atomic_t	signal;
	volatile sig_atomic_t	pid;
}	t_client;

#endif
