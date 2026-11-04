/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:03:25 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/04 15:39:22 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	char	*str;

	str = "cspxXidu";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	check_is(char c, va_list args)
{
	int	total_bit;

	total_bit = 0;
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &total_bit);
	else if (c == 'c')
		total_bit += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1, &total_bit);
	else if (c == 'p')
		to_hexadecimal_fd((unsigned long long)va_arg(args, void *), 1,
			&total_bit);
	else if (c == 'u')
		unsigned_putnbr(va_arg(args, unsigned int), &total_bit);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			print_hex(va_arg(args, unsigned int), 1, &total_bit);
		else
			print_hex(va_arg(args, unsigned int), 2, &total_bit);
	}
	if (total_bit == -1)
		return (-1);
	return (total_bit);
}

static int	ft_handle(const char *str, int *i, va_list args)
{
	if (str[*i] == '%' && str[*i + 1] && is_valid(str[*i + 1]))
	{
		(*i)++;
		return (check_is(str[*i], args));
	}
	if (str[*i] == '%' && str[*i + 1] == '%')
	{
		(*i)++;
		return (ft_putchar_fd('%', 1));
	}
	return (ft_putchar_fd(str[*i], 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		som;
	int		ret;

	if (!str || write(1, 0, 0) < 0)
		return (-1);
	som = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		ret = ft_handle(str, &i, args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		som += ret;
		i++;
	}
	va_end(args);
	return (som);
}
