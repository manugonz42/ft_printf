/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:30:11 by manugonz          #+#    #+#             */
/*   Updated: 2023/06/27 19:30:14 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_write_nbr(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_write_nbr (n / 10, fd);
		n %= 10;
	}
	n += 48;
	write(1, &n, 1);
}

int	print_unsig(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_write_nbr(n, 1);
	return (cont_dec(n));
}

int	printf_format(va_list list, const char arg)
{
	int	ret;

	ret = 0;
	if (arg == 'c')
	{
		ft_putchar_fd(va_arg(list, int), 1);
		ret = 1;
	}
	else if (arg == 's')
		ret += print_str(va_arg(list, char *));
	else if (arg == 'd' || arg == 'i')
		ret += print_int(va_arg(list, int));
	else if (arg == 'p')
		ret += to_ptr(va_arg(list, unsigned long long));
	else if (arg == 'u')
		ret += print_unsig(va_arg(list, unsigned int));
	else if (arg == 'x' || arg == 'X')
		ret += to_hexa(va_arg(list, unsigned int), arg);
	else if (arg == '%')
	{
		ft_putchar_fd('%', 1);
		ret += 1;
	}
	return (ret);
}

int	ft_printf(char const *base, ...)
{
	va_list	list;
	int		cont;
	int		ret;

	ret = 0;
	cont = 0;
	va_start(list, base);
	while (base[cont])
	{
		if (base[cont] == '%')
		{
			ret = ret + printf_format(list, base[cont + 1]);
			cont++;
		}
		else
		{
			ft_putchar_fd(base[cont], 1);
			ret += 1;
		}
		cont++;
	}
	return (ret);
}
