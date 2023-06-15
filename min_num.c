/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:52:07 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/12 16:52:40 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	min(t_stack *s, int m)
{
	int	i;
	int	index;
	int	min;

	min = INT32_MAX;
	i = 0;
	while (i < s->size)
	{
		if (s->items[i] <= min && s->items[i] >= m)
		{
			index = i;
			min = s->items[i];
		}
		i++;
	}
	return (index);
}
