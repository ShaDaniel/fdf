/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:26:25 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 21:39:57 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p_s;

	p_s = (unsigned char *)s;
	while (n--)
	{
		if (*(p_s++) == (unsigned char)c)
			return (p_s - 1);
	}
	return (NULL);
}
