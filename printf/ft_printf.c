/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moirhira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:33:32 by moirhira          #+#    #+#             */
/*   Updated: 2024/12/10 12:06:58 by moirhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handel_formats(char format, va_list args)
{
	int	ctrchar;

	ctrchar = 0;
	if (format == 'c')
		ctrchar += handel_c_and_prsnt_format((char)va_arg(args, int));
	else if (format == 's')
		ctrchar += handel_s_format(va_arg(args, char *));
	else if (format == 'p')
		ctrchar += handel_p_format((unsigned long)va_arg(args, void *));
	else if (format == 'd')
		ctrchar += handel_d_and_i_format(va_arg(args, int));
	else if (format == 'i')
		ctrchar += handel_d_and_i_format(va_arg(args, int));
	else if (format == 'u')
		ctrchar += handel_u_format((unsigned int)va_arg(args, int));
	else if (format == 'x')
		ctrchar += handel_x_format((unsigned long)va_arg(args, void *));
	else if (format == 'X')
		ctrchar += handel_x_upper_format((unsigned long)va_arg(args, void *));
	else if (format == '%')
		ctrchar += handel_c_and_prsnt_format('%');
	return (ctrchar);
}

int	process_format(const char *format, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			n += handel_formats(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			n++;
		}
		i++;
	}
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int		n;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	n = process_format(format, args);
	va_end(args);
	return (n);
}
//  int main()
// {
//     int num = 42;
//     void *ptr = &num;
//     printf("%");
//     ft_printf("test c min : %c\n", 'x');
//     printf("test s lib : %s\n", "hello");
//     ft_printf("test s min : %s\n", "hello");
//     printf("%d\n",printf("test p lib : %p\n", NULL));
//     printf("%d\n",ft_printf("test p min : %p\n", NULL));
//     printf("test d lib : %d\n", 1337);
//     ft_printf("test d min : %d\n", 1337);
//     printf("test i lib : %i\n", 42);
//     ft_printf("test i min : %i\n", 42);
//     printf("test u lib : %u\n", -42);
//     ft_printf("test u min : %u\n", -42);
//     printf("test x lib : %x\n", 2020);
//     ft_printf("test x min : %x\n", 2020);
//     printf("test X lib : %X\n", 2024);
//     ft_printf("test X min : %X\n", 2024);
//     printf("test prsnt lib : %%\n", "any way");
//     ft_printf("test prsnt min : %%\n", "any way");
	// printf("%d\n",ft_printf("hh%"));
	// printf("%d\n",printf("hh%"));
// }
