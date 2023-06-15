/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:07:19 by odouhri           #+#    #+#             */
/*   Updated: 2023/03/17 14:50:31 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*head;

	newlst = 0;
	head = lst;
	while (head != 0)
	{
		head->content = f(head->content);
		head = head->next;
	}
	head = lst;
	while (head != 0)
	{
		ft_lstadd_back(&newlst, ft_lstnew(head->content));
		head = head->next;
	}
	if (head != 0)
		del(head->content);
	return (newlst);
}
