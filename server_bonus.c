/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:15:24 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/02 22:15:28 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "file.h"
#include "includes/printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

#define MAX_BITS 8

t_signal_data	g_data = {0, 0, 0};

void	handel_signals(int sig, siginfo_t *info, void *cntx)
{
	(void)cntx;
	g_data.client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_data.rec_char = g_data.rec_char << 1;
	else if (sig == SIGUSR2)
		g_data.rec_char = (g_data.rec_char << 1) | 1;
	g_data.bits_count++;
	if (g_data.bits_count == MAX_BITS)
	{
		ft_printf("%c", g_data.rec_char);
		if (g_data.rec_char == '\0')
			kill(g_data.client_pid, SIGUSR1);
		g_data.bits_count = 0;
		g_data.rec_char = 0;
	}
	kill(g_data.client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handel_signals;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
