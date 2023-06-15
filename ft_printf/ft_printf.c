/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:02:44 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/10 18:07:23 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	condition(char c, va_list p, int count)
{
	if (c == 'c')
		count = print_c((int) va_arg(p, int), count);
	else if (c == 's')
		count = print_s(va_arg(p, char *), count);
	else if (c == 'p')
		print_p(va_arg(p, unsigned long long), &count);
	else if (c == 'd' || c == 'i')
		count = print_d(va_arg(p, int), count);
	else if (c == 'u')
		convert(va_arg(p, unsigned int), "0123456789", 10, &count);
	else if (c == 'x')
		convert(va_arg(p, unsigned int), "0123456789abcdef", 16, &count);
	else if (c == 'X')
		convert(va_arg(p, unsigned int), "0123456789ABCDEF", 16, &count);
	else if (c == '%')
		count = print_percent(count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	p;
	int		count;

	va_start(p, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = condition(str[i + 1], p, count);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(p);
	return (count);
}
