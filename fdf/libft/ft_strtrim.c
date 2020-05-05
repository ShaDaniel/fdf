/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:01:18 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/18 23:29:51 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	beg;
	size_t	end;
	size_t	i;

	beg = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t')
		beg++;
	if (s[beg] == '\0')
		return (ft_strnew(0));
	end = beg;
	while (s[end])
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	if (!(dest = malloc(end - beg + 2)))
		return (NULL);
	while (beg <= end)
		dest[i++] = s[beg++];
	dest[i] = '\0';
	return (dest);
}
