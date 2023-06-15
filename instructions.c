/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:17:43 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/15 04:49:16 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	swap(t_stack *s, char c)
{
	int	n;

	if (s->top < 2)
		return ;
	n = s->items[s->top - 2];
	s->items[s->top - 2] = s->items[s->top - 1];
	s->items[s->top - 1] = n;
	ft_printf("s%c\n", c);
}

void	push(t_stack *first, t_stack *second, char c)
{
	t_stack	tmps;
	int		n;

	if (second->top == 0)
		return ;
	n = second->items[second->top - 1];
	stack_init(&tmps, second->size - 1);
	second->top--;
	stack_itemscpy(&tmps, second, tmps.size);
	stack_destroy(second);
	*second = tmps;
	stack_init(&tmps, first->top + 1);
	stack_itemscpy(&tmps, first, tmps.size);
	stack_push(&tmps, n);
	// tmps.items[tmps.top] = n;
	// tmps.top++;
	stack_destroy(first);
	*first = tmps;
	ft_printf("p%c\n", c);
}

void	reverse_rotate(t_stack *s, char c)
{
	t_stack	tmps;
	int		n;

	n = s->items[0];
	s->items++;
	s->size--;
	s->top--;
	stack_init(&tmps, s->size + 1);
	stack_itemscpy(&tmps, s, s->size);
	s->items--;
	tmps.items[tmps.top] = n;
	tmps.top++;
	stack_destroy(s);
	*s = tmps;
	ft_printf("rr%c\n", c);
}

void	rotate(t_stack *s, char c)
{
	t_stack	tmps;
	int		n;

	n = s->items[s->top - 1];
	stack_init(&tmps, s->size);
	tmps.items++;
	tmps.size--;
	stack_itemscpy(&tmps, s, tmps.size);
	tmps.items--;
	tmps.size++;
	tmps.items[0] = n;
	stack_destroy(s);
	*s = tmps;
	ft_printf("r%c\n", c);
}
