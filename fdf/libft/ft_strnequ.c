/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:33:24 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 18:04:05 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && n-- && s1[i])
			i++;
		if (s1[i] == s2[i] || n == 0)
			return (1);
		else
			return (0);
	}
	return (2);
}
