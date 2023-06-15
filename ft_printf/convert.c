/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:18:54 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/10 18:34:26 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(unsigned long long num, char *base, int digits, int *count)
{
	int		i;
	int		tmp;
	char	arr[22];

	if (!num)
	{
		write(1, "0", 1);
		++(*count);
	}
	i = 0;
	while (num)
	{
		tmp = num % digits;
		arr[i] = base[tmp];
		num /= digits;
		i++;
	}
	*count += i;
	while (i)
	{
		i--;
		write(1, &arr[i], 1);
	}
}
