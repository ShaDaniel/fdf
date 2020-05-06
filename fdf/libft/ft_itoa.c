/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:31:41 by tjonella          #+#    #+#             */
/*   Updated: 2020/05/06 23:38:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*min_value(void)
{
	int		i;
	int		n;
	char	*arr;

	arr = (char *)malloc(12);
	n = 147483648;
	i = 11;
	arr[0] = '-';
	arr[1] = '2';
	while (i-- - 2)
	{
		arr[i] = n % 10 + '0';
		n /= 10;
	}
	arr[11] = '\0';
	return (arr);
}

char			*ft_itoa(int n)
{
	char	*num;
	int		len;

	if (n == -2147483648)
	{
		num = min_value();
		return (num);
	}
	len = ft_numlen(n);
	if (!(num = malloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	num[len] = '\0';
	while (len--)
	{
		if (len == 0 && num[0] == '-')
			break ;
		num[len] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}
