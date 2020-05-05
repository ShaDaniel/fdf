/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:48:23 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 18:04:57 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = -1;
	sub = NULL;
	if (s)
	{
		if (!(sub = malloc(len + 1)))
			return (NULL);
		while (++i < len)
			sub[i] = s[start + i];
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
