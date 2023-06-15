/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:58:53 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/14 00:41:04 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_init(t_stack *stack, int size)
{
	stack->items = malloc((size + 1) * sizeof(int));
	stack->size = size;
	stack->top = 0;
}

void	stack_push(t_stack *stack, int value)
{
	stack->items[stack->top] = value;
	stack->top++;
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	stack->size = 0;
	stack->top = 0;
}

void	stack_itemscpy(t_stack *dest, t_stack *src, int size)
{
	ft_memcpy(dest->items, src->items, size * sizeof(int));
	if (dest->top < src->top)
		dest->top = src->top;
}

void	stack_print(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		ft_printf("%d ", stack->items[i]);
		i--;
	}
	ft_printf("\n");
}
