/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:18:35 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/12 14:55:46 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "stack.h"

void	push(t_stack *first, t_stack *second, char c);
void	swap(t_stack *s, char c);
void	rotate(t_stack *s, char c);
void	reverse_rotate(t_stack *s, char c);

#endif