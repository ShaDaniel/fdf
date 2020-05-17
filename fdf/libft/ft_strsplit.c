/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:34 by tjonella          #+#    #+#             */
/*   Updated: 2020/05/17 22:51:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char const *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
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

static	char	*free_error(size_t x, char ***dim2)
{
	while (x--)
		free((*dim2)[x]);
	free(*dim2);
	return (NULL);
}

static	char	**allocate(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**dim2;
	size_t	x;

	i = -1;
	len = 1;
	x = 0;
	if (!(dim2 = (char **)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c && s[++i] && s[i] != c)
				len++;
			if (!(dim2[x++] = (char *)malloc(sizeof(char) * (len + 1))))
				return(free_error(x, &dim2));
			len = 1;
		}
		if (!s[i])
			break ;
	}
	return (dim2);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	x;
	size_t	z;

	i = 0;
	x = 0;
	z = 0;
	array = (s && c ? allocate(s, c) : NULL);
	if (array)
	{
		while (s[i])
		{
			if (s[i] != c)
			{
				while (s[i] != c && s[i])
					array[x][z++] = s[i++];
				array[x++][z] = '\0';
				z = 0;
			}
			s[i] ? i++ : i;
		}
		array[x] = NULL;
	}
	return (array);
}
