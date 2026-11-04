/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:03:25 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/03 18:48:40 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int is_valid(char c)
{
    char *str;

    str = "cspxXidu";
    while(*str)
    {
        if(*str == c)
            return 1;
        str++;
    }
    return 0;
}

int check_is (char c , va_list args)
{
    int total_bit;
    
    total_bit = 0;
    if (c == 'd' || c == 'i')
        ft_putnbr_fd(va_arg(args , int), 1 , &total_bit);
    else if (c == 'c')
        total_bit += ft_putchar_fd(va_arg(args , int) , 1);
    else if (c == 's')
        ft_putstr_fd(va_arg(args , char *) , 1 , &total_bit);
    else if (c == 'p')
        to_hexadecimal_fd((unsigned long long )va_arg(args , void *) , 1 , &total_bit);
    else if (c == 'u')
        unsigned_putnbr(va_arg(args , unsigned int) , &total_bit);
    else if (c == 'x' || c == 'X')
    {
        if (c == 'x')
            print_hex(va_arg(args , unsigned int ) , 1 , &total_bit);
        else
            print_hex(va_arg(args , unsigned int ) , 2, &total_bit);
    }
    if (total_bit == -1)
        return -1;
    return total_bit;
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int som;
    
    som = 0;
    i = 0;
    va_start(args , str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] && is_valid(str[i + 1]))
        {
            i++;
            som += check_is (str[i], args);
        }
        else if(str[i] == '%' && str[i + 1] && str[i + 1] == '%')
        {
            i++;
            som += ft_putchar_fd(str[i],1);
        }
        else
            som += ft_putchar_fd(str[i],1);
        if (som == -1)
        {
            va_end(args);
            return -1;
        }
        i++;
    }
    va_end(args);
    return som;
}