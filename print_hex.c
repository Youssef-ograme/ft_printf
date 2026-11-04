/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:43:23 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/03 18:07:06 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_hex (unsigned int nb , int is , int *som)
{    
    char *str_x;
    char *str_X;
    
    str_x = "0123456789abcdef";    
    str_X = "0123456789ABCDEF";
    if (is == 1)
    {
        if (nb >= 16)
            print_hex(nb / 16 , is , som);
        *som += ft_putchar_fd(str_x[nb % 16] ,1);
    }
    else if (is == 2)
    {
        if (nb >= 16)
            print_hex(nb / 16 , is , som);
        *som += ft_putchar_fd(str_X[nb % 16] , 1);
    }
}