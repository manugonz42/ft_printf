/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:29:01 by manugonz          #+#    #+#             */
/*   Updated: 2023/06/27 19:29:03 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

void	ft_write_nbr(unsigned int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_intlen(int n);
char	*ft_itoa(int n);
int		print_str(char *str);
int		print_int(int num);
int		cont_dec(long n);
int		print_unsig(unsigned int n);
int		printf_format(va_list list, const char arg);
int		ft_printf(char const *base, ...);
int		ptr_len(uintptr_t num);
int		print_ptr(unsigned long long num);
int		to_ptr(unsigned long long num);
int		hexa_len(unsigned int num);
int		to_hexa(long num, const char arg);
void	ft_putchar_fd(char c, int fd);

#endif