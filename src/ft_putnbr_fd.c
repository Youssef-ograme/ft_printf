/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:49:39 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/06 13:57:07 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_digit(long nb, int fd, int *som)
{
	int	ret;

	ret = ft_putchar_fd((nb % 10) + 48, fd);
	if (ret < 0)
	{
		*som = -1;
		return (0);
	}
	*som += ret;
	return (1);
}

void	ft_putnbr_fd(int n, int fd, int *som)
{
	long	nb;
	int		ret;

	nb = n;
	if (*som < 0)
		return ;
	if (nb < 0)
	{
		ret = ft_putchar_fd('-', fd);
		if (ret < 0)
		{
			*som = -1;
			return ;
		}
		*som += ret;
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd, som);
	if (*som < 0)
		return ;
	ft_print_digit(nb, fd, som);
}
