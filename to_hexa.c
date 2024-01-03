/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:29:52 by manugonz          #+#    #+#             */
/*   Updated: 2023/06/27 19:29:54 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	to_hexa(long num, const char arg)
{
	int		ret;
	char	*baseu;
	char	*basel;

	baseu = ("0123456789ABCDEF");
	basel = ("0123456789abcdef");
	ret = num;
	if (num == 0)
		return (write(1, "0", 1));
	if (num >= 16)
	{
		to_hexa(num / 16, arg);
		num %= 16;
	}
	if (arg == 'X')
		ft_putchar_fd(baseu[num], 1);
	else if (arg == 'x')
		ft_putchar_fd(basel[num], 1);
	return (hexa_len(ret));
}
/*
int main()
{
	int num;
	printf("\nnum=%d",(num = to_hexa(123456789)));
		
	return 0;
}*/
