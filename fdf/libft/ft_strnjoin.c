/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:55:24 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 18:02:04 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = -1;
	j = -1;
	dest = NULL;
	if (s1 && s2 && n > -1)
	{
		if (!(dest = malloc(ft_strlen(s1) + (ft_strlen(s2) > n ? n : ft_strlen(s2)) + 1)))
			return (NULL);
		while (s1[++i])
			dest[i] = s1[i];
		while (s2[++j] && n--)
			dest[i + j] = s2[j];
		dest[i + j] = '\0';
		return (dest);
	}
	return (NULL);
}
