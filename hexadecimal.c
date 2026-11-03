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

void to_hexadecimal_fd ( unsigned long nb , int fd , int *som)
{
    char str[16] = "0123456789abcdef";
    if (nb > 9)
        to_hexadecimal_fd(nb / 16 , fd ,som);
    *som += ft_putchar_fd(str[nb % 16],fd);
}