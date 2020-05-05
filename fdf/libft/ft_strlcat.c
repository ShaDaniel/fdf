/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:04:56 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/14 18:46:11 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len_src;
	size_t len_dst;

	i = 0;
	j = 0;
	len_src = 0;
	while (dst[i])
		i++;
	len_dst = i;
	while (src[len_src])
		len_src++;
	if (len_dst >= size)
		return (size + len_src);
	else
	{
		if (size - i - 1 > 0)
			dst[i++] = src[j++];
		while (src[j] && size - i - 1 > 0 && dst[i - 1])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (len_src + len_dst);
}
