/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:03:49 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/17 14:49:39 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;

	head = *lst;
	while (head != 0)
	{
		del(head->content);
		head = head->next;
		free(*lst);
		*lst = head;
	}
	*lst = 0;
}
