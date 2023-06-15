/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:24:40 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/15 05:04:57 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	renum(t_stack *s)
{
	int	i;
	int	m;
	int	*items;

	items = malloc(s->top * sizeof(int));
	if (items == 0)
		return ;
	m = INT32_MIN;
	i = 0;
	while (i < s->top)
	{
		m = min(s, m);
		items[i] = m;
		m = s->items[m] + 1;
		i++;
	}
	i = 0;
	while (i < s->top)
	{
		s->items[items[i]] = i;
		i++;
	}
	free(items);
}

static void	push_or_rotate(t_stack *a, t_stack *b, int shift)
{
	int	index;

	index = a->top - 1;
	while (index >= 0)
	{
		if ((!(a->items[a->top - 1] & (1 << 31))
				&& (a->items[a->top - 1] & shift))
			|| ((a->items[a->top - 1] & (1 << 31))
				&& (a->items[a->top - 1] & shift)))
			rotate(a, 'a');
		else
			push(b, a, 'b');
		index--;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	shift;

	renum(a);
	shift = 1;
	while (!(shift & (1 << 30)))
	{
		push_or_rotate(a, b, shift);
		while (b->top > 0)
			push(a, b, 'a');
		if (!check_issorted(a))
		{
			stack_destroy(b);
			exit(0);
		}
		shift <<= 1;
	}
}

// static void	ra_or_rra(t_stack *a, int m)
// {
// 	if (m < (a->top / 2))
// 	{
// 		while (m >= 0)
// 		{
// 			reverse_rotate(a);
// 			ft_printf("rra\n");
// 			m--;
// 		}
// 	}
// 	else
// 	{
// 		while (m < a->top - 1)
// 		{
// 			rotate(a);
// 			ft_printf("ra\n");
// 			m++;
// 		}
// 	}
// }

// static void	push_min(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	m;

// 	i = 0;
// 	m = min(a, 0);
// 	if (m == a->top - 1)
// 	{
// 		push(b, a);
// 		ft_printf("pb\n");
// 	}
// 	else if (m == a->top - 2)
// 	{
// 		swap(a);
// 		ft_printf("sa\n");
// 	}
// 	else if (m < a->top - 2)
// 		ra_or_rra(a, m);
// }

// void	sort_small(t_stack *a, t_stack *b)
// {
// 	while (a->top > 0)
// 	{
// 		push_min(a, b);
// 	}
// 	while (b->top > 0)
// 	{
// 		push(a, b);
// 		ft_printf("pa\n");
// 	}
// }
