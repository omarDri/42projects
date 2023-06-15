/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:05:03 by odouhri           #+#    #+#             */
/*   Updated: 2023/06/14 02:05:06 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_check.h"

static int	isflow(char *nums, char *m, int i)
{
	while (nums[i])
	{
		if (nums[i] > m[i])
			return (0);
		else if (nums[i] < m[i])
			break ;
		i++;
	}
	return (1);
}

static int	free_printerr(char *max, char *min)
{
	free(max);
	free(min);
	ft_printerr("Error\n");
	return (0);
}

int	check_overflow(char *nums)
{
	int		i;
	int		isnegative;
	char	*max;
	char	*min;

	max = ft_itoa(2147483647);
	min = ft_itoa(-2147483648);
	i = 0;
	if (nums[i] == '-')
		isnegative = 1;
	else
		isnegative = 0;
	while (nums[i])
		i++;
	if (isnegative && i == 11 && !isflow(nums, min, 1))
		return (free_printerr(max, min));
	else if (!isnegative && i == 10 && !isflow(nums, max, 0))
		return (free_printerr(max, min));
	else if ((i > 11 && isnegative) || (i > 10 && !isnegative))
		return (free_printerr(max, min));
	free(max);
	free(min);
	return (1);
}

int	check_digits(char *nums)
{
	int	i;

	i = 0;
	if (nums[i] == '\0')
		return (0);
	else if (nums[i] == '-' && nums[i + 1] == '\0')
	{
		ft_printerr("Error\n");
		return (0);
	}
	else if (nums[i] == '-')
		i++;
	while (nums[i])
	{
		if (!ft_isdigit(nums[i]))
		{
			ft_printerr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
