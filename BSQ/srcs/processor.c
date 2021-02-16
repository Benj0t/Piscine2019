/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:57:13 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/21 21:34:28 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

void				findbiggest(t_stock *val, t_coordinates *co)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (val->tab[y])
	{
		x = 0;
		while ((val->tab)[y][x] != -1)
		{
			if ((unsigned int)(val->tab)[y][x] > co->max)
			{
				co->x = x;
				co->y = y;
				co->max = (unsigned int)(val->tab)[y][x];
			}
			x++;
		}
		y++;
	}
}

void				fillgrid(t_stock *val)
{
	unsigned int	xref;
	unsigned int	yref;

	val->co.max = 0;
	findbiggest(val, &(val->co));
	yref = val->co.y - val->co.max + 1;
	while (yref <= val->co.y)
	{
		xref = val->co.x - val->co.max + 1;
		while (xref <= val->co.x)
		{
			val->map[yref][xref] = val->cset.fill;
			xref++;
		}
		yref++;
	}
}
