/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:26:40 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 18:03:37 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dest[i] = f(i, s[i]);
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
