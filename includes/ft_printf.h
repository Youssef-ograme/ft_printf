/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:03:23 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/04 11:44:36 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	to_hexadecimal_fd(unsigned long long nb, int fd, int *som);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd, int *som);
char	*ft_putstr_fd(char *s, int fd, int *som);
void	unsigned_putnbr(unsigned long nb, int *som);
void	print_hex(unsigned int nb, int is, int *som);
#endif
