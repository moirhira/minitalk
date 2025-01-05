/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:37:38 by moirhira          #+#    #+#             */
/*   Updated: 2025/01/03 20:38:08 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
typedef struct s_signal_data
{
	int			bits_count;
	char		rec_char;
	pid_t		client_pid;
}				t_signal_data;
