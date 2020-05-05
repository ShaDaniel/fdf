/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:16:08 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 21:25:11 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_src >= p_dst)
	{
		while (len--)
			*(p_dst++) = *(p_src++);
	}
	else
	{
		while (len--)
			*(p_dst + len) = *(p_src + len);
	}
	return (dst);
}
