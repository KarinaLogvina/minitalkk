/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:44:35 by urosby            #+#    #+#             */
/*   Updated: 2022/04/20 20:14:54 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	error(pid_t pid)
{
	int i;
	i = 0;
	while (--i)
	{
		usleep(50);
		kill(pid, SIGUSR2);
	}
	write(1, "Signal lost\n", 13);
	exit (0);
}

static int	mini_atoi(const char *str)
{
	int			i;
	long int	number;

	i = 0;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number > 2147483647)
			return (0);
		number = number * 10 + (str[i++] - '0');
	}
	return ((int)number);
}

static void	send_string(int pid, char *str)
{
	static int				i = 8;
	static unsigned char	ch = 0;
	static pid_t	server_pid = 0;
	
	if (str)
	{
		server_pid = pid;
		i = 8;
		ch = *str;
	}
	if (!i)
	{
		ch = *(++str);
		i = 8;
		if (!ch)
			error(server_pid);
	}
	if (ch && ch >> --i & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

static void server_response(int sig, siginfo_t *siginfo, void *context)
{
	static int	signal = 0;
	
	(void)context;
	(void)siginfo;
	if(sig == SIGUSR1)
	{
		write(1, "Receive: ", 9);
		ft_putnbr_fd(++signal, 1);
	}
	send_string(0, 0);
}

int	main(int ac, char *av[])
{
	struct	sigaction signal;

	if (ac != 3)
	{
		ft_printf("Wrong input!\n");
		return (1);
	}
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = server_response;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	ft_printf("Sent bytes: %d\n", (int)ft_strlen(av[2]));
	send_string(mini_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
