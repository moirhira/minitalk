/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:05:19 by moirhira          #+#    #+#             */
/*   Updated: 2024/11/28 22:05:28 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handel_p_format(unsigned long adrs)
{
	unsigned long	restmod;
	char			hexa[17];
	int				j;
	int				n;

	j = 0;
	if (!adrs)
		return (write(1, "(nil)", 5));
	while (adrs)
	{
		restmod = adrs % 16;
		if (restmod < 10)
			hexa[j++] = ('0' + restmod);
		else
			hexa[j++] = ('a' + (restmod - 10));
		adrs /= 16;
	}
	write(1, "0x", 2);
	n = j + 2;
	while (--j >= 0)
		write(1, &hexa[j], 1);
	return (n);
}

int	handel_d_and_i_format(int nbr)
{
	int	n;

	n = 0;
	if (nbr == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		n++;
	}
	if (nbr >= 10)
	{
		n += handel_d_and_i_format(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		n++;
	}
	return (n);
}

int	handel_u_format(unsigned int nbr)
{
	char		res[11];
	int			k;
	int			n;

	k = 0;
	if (nbr == 0)
		res[k++] = '0';
	else
	{
		while (nbr > 0)
		{
			res[k++] = '0' + (nbr % 10);
			nbr /= 10;
		}
	}
	n = k;
	while (--k >= 0)
		write(1, &res[k], 1);
	return (n);
}

int	handel_x_format(unsigned int adrs)
{
	unsigned int	restmod;
	char			hex[8];
	int				i;
	int				n;

	i = 0;
	if (adrs == 0)
		return (write(1, "0", 1));
	else
	{
		while (adrs)
		{
			restmod = adrs % 16;
			if (restmod < 10)
				hex[i++] = ('0' + restmod);
			else
				hex[i++] = ('a' + (restmod - 10));
			adrs /= 16;
		}
	}
	n = i;
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (n);
}

int	handel_x_upper_format(unsigned int adrs)
{
	unsigned int	restmod;
	char			hex[8];
	int				i;
	int				n;

	i = 0;
	if (adrs == 0)
		return (write(1, "0", 1));
	else
	{
		while (adrs)
		{
			restmod = adrs % 16;
			if (restmod < 10)
				hex[i++] = ('0' + restmod);
			else
				hex[i++] = ('A' + (restmod - 10));
			adrs /= 16;
		}
	}
	n = i;
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (n);
}
