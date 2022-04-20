/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karinalogvina <karinalogvina@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:20:53 by urosby            #+#    #+#             */
/*   Updated: 2022/04/19 15:26:10 by karinalogvi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handel_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int	pid = 0;
	static char	c = 0;
	static int	i = 0;

	(void)context;
	if (!pid || pid != siginfo->si_pid)
	{
		i = 0;
		c = 0;
		pid = siginfo->si_pid;
	}
	c |= (signal == SIGUSR1);
	if (++i == 8)
	{	
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("PID: %d\n", getpid());
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = handel_signal;
	if (sigaction(SIGUSR1, &signal, NULL) < 0)
		ft_printf("Sigaction error");
	if (sigaction(SIGUSR2, &signal, NULL) < 0)
		ft_printf("Sigaction error");
	while (1)
		pause();
	return (0);
}
