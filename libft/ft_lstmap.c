/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:25:05 by calbar-c          #+#    #+#             */
/*   Updated: 2023/10/11 11:40:01 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		new_lst = ft_lstnew(temp);
		if (!new_lst)
		{
			(*del)(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_lst);
		lst = lst->next;
	}
	return (head);
}
