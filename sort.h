/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:24:57 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/12 16:53:39 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"
# include "instructions.h"
# include "input_check.h"

int		min(t_stack *s, int m);
void	sort_big(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

#endif