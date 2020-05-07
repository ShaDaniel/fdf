/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:46:00 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 22:00:29 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	size_t	len;
	size_t	i;
	char	*place;

	i = 0;
	if (!s1 || n < 0)
		return (NULL);
	len = ft_strlen(s1);
	len = len > n ? n : len;
	if (!(place = (char *)malloc(len + 1)))
		return (NULL);
	while (i <= len)
	{
		place[i] = s1[i];
		i++;
	}
	return (place);
}
