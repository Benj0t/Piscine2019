/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 06:58:08 by mreho             #+#    #+#             */
/*   Updated: 2019/08/21 20:23:38 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

unsigned int		grepsmallest(t_stock *val, unsigned int x, unsigned int y)
{
	val->co.x = val->tab[y][x - 1];
	val->co.y = val->tab[y - 1][x];
	val->co.z = val->tab[y - 1][x - 1];
	if (val->co.x < val->co.y && val->co.x < val->co.z)
		return (val->co.x);
	if (val->co.y < val->co.x && val->co.y < val->co.z)
		return (val->co.y);
	else
		return (val->co.z);
}

void				findbsq(t_stock *val)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	min;

	y = 1;
	while (y < val->tbl.height)
	{
		x = 1;
		while (x < val->tbl.weight)
		{
			min = grepsmallest(val, x, y);
			if (val->tab[y][x] == 0)
				x++;
			else
				val->tab[y][x++] = min + 1;
		}
		y++;
	}
}
