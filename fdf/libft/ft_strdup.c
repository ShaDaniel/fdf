/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:46:00 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/12 22:00:29 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*place;

	i = 0;
	len = ft_strlen(s1);
	if (!(place = (char *)malloc(len + 1)))
		return (NULL);
	while (i <= len)
	{
		place[i] = s1[i];
		i++;
	}
	return (place);
}
