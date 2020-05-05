/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:12:52 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/20 23:14:58 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*begin;

	if (!(begin = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		begin->content_size = 0;
		begin->content = NULL;
		begin->next = NULL;
		return (begin);
	}
	if (!(begin->content = (void *)malloc(content_size)))
	{
		free(begin);
		return (NULL);
	}
	begin->content = ft_memcpy(begin->content, content, content_size);
	begin->content_size = content_size;
	begin->next = NULL;
	return (begin);
}
