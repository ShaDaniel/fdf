/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freechararr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:10:49 by tjonella          #+#    #+#             */
/*   Updated: 2020/05/13 18:57:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freechararr(char **arr)
{
	int		i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}
