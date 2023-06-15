/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:39:27 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/17 14:51:29 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			*((char *) dest + i - 1) = *((char *) src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((char *) dest + i) = *((char *) src + i);
			i++;
		}
	}
	return (dest);
}
