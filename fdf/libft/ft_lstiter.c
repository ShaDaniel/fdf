/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:51:08 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/20 22:30:35 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ptr;

	ptr = lst;
	if (lst && f)
	{
		while (ptr)
		{
			f(ptr);
			ptr = ptr->next;
		}
	}
}
