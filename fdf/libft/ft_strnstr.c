/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:28:11 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 15:29:56 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t save_i;

	i = -1;
	j = 0;
	save_i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[++i] && len--)
	{
		if (haystack[i] == needle[j])
		{
			save_i = i;
			while (haystack[save_i++] == needle[j] && needle[j++] && len + 1)
				len--;
			if (needle[j - 1] == '\0')
				j--;
			if (!needle[j])
				return ((char *)&haystack[i]);
			len = len + (save_i - i);
		}
		j = 0;
	}
	return (NULL);
}
