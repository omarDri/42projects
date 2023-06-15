/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:01:22 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/10 16:56:44 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c, int count)
{
	ft_putchar_fd(c, 1);
	return (++count);
}

int	print_s(char *s, int count)
{
	if (s == 0)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		count += ft_strlen(s);
	}
	return (count);
}

void	print_p(unsigned long long num, int *count)
{
	write(1, "0x", 2);
	convert(num, "0123456789abcdef", 16, count);
	*count += 2;
}

int	print_d(int num, int count)
{
	char	*s;

	s = ft_itoa(num);
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (count);
}

int	print_percent(int count)
{
	ft_putchar_fd('%', 1);
	return (++count);
}
