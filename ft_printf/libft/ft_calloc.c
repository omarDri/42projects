/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:54:27 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/17 14:47:54 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (0);
	arr = malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
