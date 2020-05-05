/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:50:58 by tjonella          #+#    #+#             */
/*   Updated: 2019/04/16 15:44:39 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	res;
	int		sign;
	size_t	i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + str[i++] - 48;
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	else if (res > 9223372036854775807 && sign == -1)
		return (0);
	return (res * sign);
}
