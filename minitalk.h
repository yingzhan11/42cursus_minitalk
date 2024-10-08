/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:51:48 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/15 14:07:55 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

# define TIMEOUT 10000000

typedef struct s_client
{
	int	signal;
	int	pid;
}	t_client;

void	error_exit(char *info);

#endif
