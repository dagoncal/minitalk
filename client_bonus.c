/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:00 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/06 16:46:09 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error(char	*str)
{
	if (str)
		free(str);
	ft_printf("client: Unexpected error\n");
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			error(str);
		return (0);
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*message = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		message = ft_strdup(str);
	if (!message)
		error(0);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR1) == -1)
				error(message);
		}
		else if (kill(s_pid, SIGUSR2) == -1)
			error(message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_printf("client: server ended unexpectdly\n");
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_printf("client: Operation successfully\n");
		exit(EXIT_SUCCESS);
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
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	pid = ft_atoi(argv[1]);
	send_bit(pid, argv[2]);
	while (1)
		pause();
}
