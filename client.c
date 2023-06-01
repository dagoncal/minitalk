/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:00 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/31 18:28:42 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error()
{
	ft_putstr("client: Unexpected error\n");
	exit(EXIT_FAILURE);
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i++ != 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			error();
		usleep(80);
	}
}

void	send_bit(int pid, char *message)
{
	int	i;
	int	c;

	i = 0;
	while (*message)
	{
		c = *(message);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(80);
		}
		message++;
		i = 0;
	}
	send_null(pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("client: Invalid arguments!\n");
		ft_putstr("\tcorrect format [./client SERVER_PID MESSAGE]\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_bit(pid, argv[2]);
	return (EXIT_SUCCESS);
}
