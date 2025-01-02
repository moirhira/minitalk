/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 21:51:44 by moirhira          #+#    #+#             */
/*   Updated: 2024/12/31 21:51:47 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "includes/printf/ft_printf.h"

#define MAX_BITS 8

int bits_count = 0;
char rec_char = 0;

void handel_signals(int sig)
{
    
    if (sig == SIGUSR1)
        rec_char = rec_char << 1;
    else if (sig == SIGUSR2)
        rec_char = (rec_char << 1) | 1;
    bits_count++;

    if (bits_count == MAX_BITS)
    {
        write(1, &rec_char, 1);
        bits_count = 0;
        rec_char = 0;
    }
}



int main()
{
    ft_printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handel_signals);
    signal(SIGUSR2, handel_signals);

    while (1)
    {   
        pause();
    }
    return (0);
}