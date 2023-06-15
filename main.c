/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:35 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/14 01:51:10 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_check.h"
#include "sort.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	count_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_inputs(t_stack *a, char **str, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (!check_digits(str[i]) || !check_overflow(str[i]))
		{
			if (str[0] != 0 && str[1] == 0)
				free_str(str);
			stack_destroy(a);
			exit(0);
		}
		stack_push(a, ft_atoi(str[i]));
		i--;
	}
	if (str[0] != 0 && str[1] == 0)
		free_str(str);
	check_dup(a);
	check_issorted(a);
}

void	assign_values(char **argv, t_stack *a)
{
	char	**str;
	int		size;

	str = ++argv;
	if (str[0] != 0 && str[1] == 0)
		str = ft_split(str[0], ' ');
	size = count_args(str);
	stack_init(a, size);
	check_inputs(a, str, size);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	assign_values(argv, &a);
	stack_init(&b, 1);
	if (a.top <= 6)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	stack_destroy(&a);
	stack_destroy(&b);
	return (0);
}
