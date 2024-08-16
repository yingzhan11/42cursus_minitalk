/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:53:56 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/16 14:54:03 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
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
