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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>




void handel_signals(int sig)
{
    printf("Caught signal exiting gracefully...\n");
    exit(0);
}



int main()
{
    printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handel_signals);
    signal(SIGUSR2, handel_signals);

    while (1)
    {   
        printf("waiting....\n");
        sleep(1);
    }
    return (0);
}

