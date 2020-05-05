/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:08:30 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 13:46:34 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == s[i])
		return ((char *)&s[i]);
	while (i + 1)
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
