/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:51:22 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/06 13:57:50 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_putnbr(unsigned long nb, int *som)
{
	int	ret;

	if (*som == -1)
		return ;
	if (nb > 9)
		unsigned_putnbr(nb / 10, som);
	if (*som == -1)
		return ;
	ret = ft_putchar_fd((nb % 10) + '0', 1);
	if (ret < 0)
		*som = -1;
	else
		*som += ret;
}
