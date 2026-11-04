/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:03:17 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/03 18:05:09 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void recrsive_hex (unsigned long nb , int fd , int *som)
{
    char str[16] = "0123456789abcdef";
      if (nb >= 16)
        recrsive_hex(nb / 16 , fd ,som);
    *som += ft_putchar_fd(str[nb % 16],fd);
}

void to_hexadecimal_fd ( unsigned long nb , int fd , int *som)
{
    if (!nb)
    {
        ft_putstr_fd("(nil)",fd,som);
        return;
    }
    else 
        ft_putstr_fd("0x",fd,som);
    recrsive_hex(nb,fd,som);
}