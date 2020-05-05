/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:52:39 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/20 20:56:57 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countlst(t_list *list)
{
	int		elems;
	t_list	*ptr;

	ptr = list;
	elems = 0;
	while (ptr)
	{
		elems++;
		ptr = ptr->next;
	}
	return (elems);
}
