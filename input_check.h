/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:05:14 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/15 04:51:09 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECK_H
# define INPUT_CHECK_H
# include "stack.h"

void	ft_printerr(char *str);
int		check_overflow(char *nums);
int		check_digits(char *nums);
int		check_issorted(t_stack *s);
int		check_dup(t_stack *s);

#endif