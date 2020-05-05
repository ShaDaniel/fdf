/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:00:42 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 18:03:00 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (s)
	{
		while (s[i])
			i++;
		if (!(dest = malloc(i + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			dest[i] = f(s[i]);
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
