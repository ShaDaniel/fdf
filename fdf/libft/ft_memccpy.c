/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:40:37 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 20:51:15 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n--)
	{
		*(p_dst++) = *(p_src++);
		if (*(p_src - 1) == (unsigned char)c)
			return (p_dst);
	}
	return (NULL);
}
