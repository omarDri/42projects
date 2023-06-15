/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:03:49 by odouhri           #+#    #+#             */
/*   Updated: 2023/05/16 00:24:00 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct stack
{	
	int	*items;
	int	size;
	int	top;
}				t_stack;
void	stack_init(t_stack *stack, int size);
void	stack_destroy(t_stack *stack);
void	stack_itemscpy(t_stack *dest, t_stack *src, int size);
void	stack_push(t_stack *stack, int value);
void	stack_print(t_stack *s);

#endif