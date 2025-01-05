/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:33:42 by moirhira          #+#    #+#             */
/*   Updated: 2024/12/10 12:07:31 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
size_t	ft_strlen(char *str);
int		handel_c_and_prsnt_format(char c);
int		handel_s_format(char *str);
int		handel_p_format(unsigned long adrs);
int		handel_d_and_i_format(int nbr);
int		handel_u_format(unsigned int nbr);
int		handel_x_format(unsigned int adrs);
int		handel_x_upper_format(unsigned int adrs);
int		ft_printf(const char *format, ...);

#endif
