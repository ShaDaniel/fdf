/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:06:54 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/18 23:52:51 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *ptr1;
	t_list *ptr2;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst)->content, f(lst)->content_size);
	ptr1 = lst;
	ptr2 = new_list;
	ptr1 = ptr1->next;
	while (ptr1)
	{
		ptr2->next = ft_lstnew(f(ptr1)->content, f(ptr1)->content_size);
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
	return (new_list);
}
