/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:00 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/09 16:16:53 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(void)
{
	ft_printf("client: Unexpected error\n");
	exit(EXIT_FAILURE);
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
			{
				if (kill(pid, SIGUSR1) == -1)
					error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error();
			}
			i++;
			usleep(100);
		}
		message++;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("client: Invalid arguments!\n");
		ft_printf("\tcorrect format [./client SERVER_PID MESSAGE]\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_bit(pid, argv[2]);
	return (EXIT_SUCCESS);
}
