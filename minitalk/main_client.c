/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karinalogvina <karinalogvina@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:44:35 by urosby            #+#    #+#             */
/*   Updated: 2022/04/19 15:24:38 by karinalogvi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(void)
{
	write(1, "Signal lost", 12);
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
	int				i;
	unsigned char	ch;
	
	while (*str)
	{
		i = 8;
		ch = *str++;
		while (i--)
		{
			if (ch >> i & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error();
			}
			usleep(900);
		}
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = mini_atoi(av[1]);
		if (pid != 0)
			send_string(pid, av[2]);
		else
			ft_printf("Wrong pid!");
	}
	else
		ft_printf("Wrong input!");
	return (0);
}
