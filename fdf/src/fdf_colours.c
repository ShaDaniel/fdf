/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 20:55:32 by marvin            #+#    #+#             */
/*   Updated: 2020/05/17 22:31:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			balance_colours(int c1, int c2, double growth)
{
	double weight;

	if (growth >= 0.95)
		weight = 1.0;
	else if (growth >= 0.85)
		weight = 0.9;
	else if (growth >= 0.75)
		weight = 0.8;
	else if (growth >= 0.65)
		weight = 0.7;
	else if (growth >= 0.55)
		weight = 0.6;
	else if (growth >= 0.45)
		weight = 0.5;
	else if (growth >= 0.35)
		weight = 0.4;
	else if (growth >= 0.25)
		weight = 0.3;
	else if (growth >= 0.15)
		weight = 0.2;
	else if (growth >= 0.05)
		weight = 0.1;
	else
		weight = 0;
	return ((int)(c1 * weight + c2 * (1 - weight)));
}

int			fdf_colour_get(t_point *p)
{
	int		red;
	int		green;
	int		blue;

	if (!p->colour_f)
		p->colour_f = WHITE;
	red = balance_colours(((p->colour_f >> 16) & 0xFF),
		((p->colour_s >> 16) & 0xFF), p->curr_growth);
	green = balance_colours(((p->colour_f >> 8) & 0xFF),
		((p->colour_s >> 8) & 0xFF), p->curr_growth);
	blue = balance_colours((p->colour_f & 0xFF),
		(p->colour_s & 0xFF), p->curr_growth);
	p->curr_growth += p->clr_growth;
	return ((red << 16) | (green << 8) | blue);
}

uint32_t	fdf_parse_colour(char *clr)
{
	uint32_t	colour;

	colour = 0;
	if (!clr[0] || !clr[1] || clr[0] != '0' || clr[1] != 'x'
				|| !clr[2] || ft_strlen(clr) > 8)
		fdf_error(ECOLOUR);
	clr += 2;
	while (*clr)
	{
		colour *= 16;
		if (*clr >= '0' && *clr <= '9')
			colour += *clr - '0';
		else if (*clr >= 'a' && *clr <= 'f')
			colour += *clr - 'a' + 10;
		else if (*clr >= 'A' && *clr <= 'F')
			colour += *clr - 'A' + 10;
		else
			fdf_error(ECOLOUR);
		clr++;	
	}
	return (colour);
}