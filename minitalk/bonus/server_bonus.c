/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:20:53 by urosby            #+#    #+#             */
/*   Updated: 2022/04/20 20:02:02 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handel_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int	pid = 0;
	static char	c = 0;
	static int	i = 0;

	(void)context;
	if (!pid)
		pid = siginfo->si_pid;
	c |= (signal == SIGUSR1);
	if (++i == 8)
	{	
		i = 0;
		write(1, &c, 1);
		c = 0;
		kill(pid, SIGUSR2);
	}
	else
	{
		c = c << 1;
		kill(pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("PID: %d\n", getpid());
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = handel_signal;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
