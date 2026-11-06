/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:49:42 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/06 11:41:54 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putstr_fd(char *s, int fd, int *som)
{
	int	i;
	int	ret;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ret = ft_putchar_fd(s[i++], fd);
		if (ret < 0)
		{
			*som = -1;
			return (NULL);
		}
		*som += ret;
	}
	return (s);
}
