/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:03 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/30 16:44:04 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error()
{
	ft_putstr("server: Unexpected error\n");
	exit(EXIT_FAILURE);
}

void	print_char(char c)
{
	write(1, &c, 1);
	if (c == '\0')
		ft_putstr("\n");
}

void	handler_sigusr(int signum)
{
	static unsigned char	c = 0;
	static int	bits = 0 ;

	if (signum == SIGUSR1)
		c = (c << 1) | 0b00000001;
	else if (signum == SIGUSR2)
		c = c << 1;
	bits++;
	if (bits == 8)
	{
		print_char(c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
	{
		signal(SIGUSR1, handler_sigusr);
		signal(SIGUSR2, handler_sigusr);
	}
	return (0);
}
