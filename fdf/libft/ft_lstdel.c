/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:41:58 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/18 21:35:52 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	ptr = *alst;
	while (ptr)
	{
		ptr = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = ptr;
	}
}
