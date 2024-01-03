/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:30:23 by manugonz          #+#    #+#             */
/*   Updated: 2023/06/27 19:30:25 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	cont;

	cont = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[cont])
	{
		ft_putchar_fd(str[cont], 1);
		cont++;
	}
	return (cont);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	print_int(int num)
{
	int		ret;
	char	*str;

	ret = 0;
	str = ft_itoa(num);
	ret = print_str(str);
	free(str);
	return (ret);
}

int	cont_dec(long n)
{
	int	cont;

	cont = 0;
	while (n)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}
