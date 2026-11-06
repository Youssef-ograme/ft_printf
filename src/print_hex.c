/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:43:23 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/06 12:00:21 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int nb, int is, int *som)
{
	char	*str_l;
	char	*str_u;
	int		ret;

	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (*som < 0)
		return ;
	if (nb >= 16)
		print_hex(nb / 16, is, som);
	if (*som < 0)
		return ;
	if (is == 1)
		ret = ft_putchar_fd(str_l[nb % 16], 1);
	else if (is == 2)
		ret = ft_putchar_fd(str_u[nb % 16], 1);
	else
		return ;
	if (ret < 0)
		*som = -1;
	else
		*som += ret;
}
