/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:36:30 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 15:47:25 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dest;

	if (!(dest = malloc(size)))
		return (NULL);
	dest = ft_memset(dest, 0, size);
	return (dest);
}
