/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 02:46:43 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/20 21:31:22 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest;

	if (size + 1 == 0)
		return (NULL);
	if (!(dest = malloc(size + 1)))
		return (NULL);
	if (!(dest = ft_memset(dest, 0, size + 1)))
		return (NULL);
	return (dest);
}
