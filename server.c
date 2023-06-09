/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:03 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/09 16:16:43 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(void)
{
	ft_printf("server: Unexpected error\n");
	exit(EXIT_FAILURE);
}

void	handler_sigusr(int signum)
{
	static unsigned char	c = 0;
	static int				bits = 0 ;

	if (signum == SIGUSR1)
		c = (c << 1) | 0b00000001;
	else if (signum == SIGUSR2)
		c = c << 1;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler_sigusr);
		signal(SIGUSR2, handler_sigusr);
	}
	return (EXIT_SUCCESS);
}
