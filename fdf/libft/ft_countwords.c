/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:27:38 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/20 20:57:18 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
	}
	return (words);
}
