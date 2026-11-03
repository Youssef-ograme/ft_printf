/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:51:22 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/03 18:06:39 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void unsigned_putnbr (int n , int *som)
{
    long nb;
    nb = n;
    if (nb < 0)
        nb = (unsigned int)nb;
    if (nb > 9)
        unsigned_putnbr(nb / 10 , som);
    *som += ft_putchar_fd((nb % 10) + 48 ,1);
}