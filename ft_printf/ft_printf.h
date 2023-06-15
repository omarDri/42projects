/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:48:45 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/10 17:00:06 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_c(int c, int count);
int		print_s(char *s, int count);
void	print_p(unsigned long long num, int *count);
int		print_d(int num, int count);
int		print_percent(int count);
int		print(char c, int count);
void	convert(unsigned long long num, char *base, int digits, int *count);

#endif