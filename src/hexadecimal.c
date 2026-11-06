/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:03:17 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/06 13:58:19 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recrsive_hex(unsigned long long nb, int fd, int *som)
{
	char	*str;
	int		ret;

	str = "0123456789abcdef";
	if (*som < 0)
		return ;
	if (nb >= 16)
		recrsive_hex(nb / 16, fd, som);
	if (*som < 0)
		return ;
	ret = ft_putchar_fd(str[nb % 16], fd);
	if (ret < 0)
		*som = -1;
	else
		*som += ret;
}

void	to_hexadecimal_fd(unsigned long long nb, int fd, int *som)
{
	if (!nb)
	{
		ft_putstr_fd("(nil)", fd, som);
		return ;
	}
	ft_putstr_fd("0x", fd, som);
	if (*som < 0)
		return ;
	recrsive_hex(nb, fd, som);
}
