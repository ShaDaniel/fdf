/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:51:15 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 14:51:01 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t save_i;

	i = 0;
	j = 0;
	save_i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			save_i = i;
			while ((haystack[save_i] == needle[j]) && needle[j++])
				save_i++;
			if (needle[j - 1] == '\0')
				j--;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
