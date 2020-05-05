/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:31:46 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 21:40:35 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p_s1;
	unsigned char *p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*(p_s1++) - *(p_s2++) != 0)
			return (*(p_s1 - 1) - *(p_s2 - 1));
	}
	return (0);
}
