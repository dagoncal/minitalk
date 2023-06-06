/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:03 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/06 16:47:06 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error(int pid, char *str)
{
	if (str)
		free(str);
	ft_printf("server: Unexpected error\n");
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

char	*print_string(char *str)
{
	ft_printf("%s", str);
	free(str);
	return (NULL);
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_straddc(message, c);
		else
			message = print_string(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid, message);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while (1)
		pause();
}
