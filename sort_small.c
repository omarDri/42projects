/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:16 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/12 17:45:11 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	base_case(t_stack *s)
{
	int	i;
	int	m;

	m = INT32_MIN;
	i = 0;
	while (i < 3)
	{
		m = min(s, m);
		m = s->items[m] + 1;
		i++;
	}
	return (m);
}

static void	sort_base(t_stack *s, char c)
{
	if (s->top < 1)
		return ;
	while (1)
	{
		if (s->top > 2 && s->items[s->top - 2] > s->items[s->top - 1]
			&& s->items[s->top - 2] > s->items[s->top - 3])
			reverse_rotate(s, c);
		else if (s->top > 2 && s->items[s->top - 1] > s->items[s->top - 2]
			&& s->items[s->top - 1] > s->items[0])
			rotate(s, c);
		else
		{
			if (s->items[s->top - 1] > s->items[s->top - 2])
				swap(s, c);
			break ;
		}
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	m;

	m = base_case(a);
	while (a->top > 3)
	{
		if (a->items[a->top - 1] >= m)
			push(b, a, 'b');
		else
			rotate(a, 'a');
	}
	sort_base(b, 'b');
	sort_base(a, 'a');
	while (b->top > 0)
	{
		push(a, b, 'a');
		rotate(a, 'a');
	}
}
