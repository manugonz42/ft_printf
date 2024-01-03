/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:30:34 by manugonz          #+#    #+#             */
/*   Updated: 2023/06/27 19:30:35 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
		res = 1;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	num;
	int		l;
	char	*str;

	num = (long)n;
	l = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = 0 + 48;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[l] = '\0';
	while (num)
	{
		str[--l] = 48 + num % 10;
		num /= 10;
	}
	return (str);
}

int	ptr_len(uintptr_t num)
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

int	print_ptr(unsigned long long num)
{
	int		i;
	int		j;
	int		temp;
	int		ret;
	char	hexa_number[100];

	ret = ptr_len(num);
	i = 1;
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa_number[i++] = temp;
		num = num / 16;
	}
	j = i - 1;
	while (j > 0)
	{
		ft_putchar_fd(hexa_number[j], 1);
		j--;
	}
	return (ret + 2);
}

int	to_ptr(unsigned long long num)
{
	int	a;

	write (1, "0x", 2);
	if (num == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		a = print_ptr(num);
	return (a);
}
/*
int main()
{
	int	 num, e;
	char	*p = malloc(sizeof(char *));
	to_ptr((unsigned long long)p);
	return 0;
}*/
