/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 21:51:54 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/03 20:11:45 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

int		ft_atoi(const char *str);
int		g_flag = 0;

void	handel_ack(int sig, siginfo_t *info, void *cntx)
{
	(void)info;
	(void)cntx;
	if (sig == SIGUSR1)
	{
		g_flag = 1;
	}
}

void	send_by_char(int server_pid, char c)
{
	int (i), (bit);
	i = 8;
	while (i--)
	{
		bit = c >> i & 1;
		if (!bit)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("ERR SENDING SIGNAL 1!\n");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("ERR SENDING SIGNAL 2!\n");
				exit(1);
			}
		}
		while (!g_flag)
			usleep(0);
		g_flag = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	char				*str;
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handel_ack;
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("Invalid PID!\n");
			return (1);
		}
		sigaction(SIGUSR1, &sa, NULL);
		i = 0;
		str = av[2];
		while (str[i])
			send_by_char(pid, str[i++]);
		send_by_char(pid, '\0');
	}
	else
		ft_printf("You Must enter : PID & Message\n");
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}
