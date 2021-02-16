/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:35:24 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/21 21:08:16 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char		convertmap(t_stock *val)
{
	unsigned int	i;
	unsigned int	j;

	if (!(val->tab = (int **)malloc(sizeof(int *) * (val->tbl.height + 1))))
		return (0);
	i = 0;
	while (i < val->tbl.height)
	{
		if (!(val->tab[i] = (int *)malloc(sizeof(int) * (val->tbl.weight + 1))))
			return (0);
		j = 0;
		while (j < val->tbl.weight)
		{
			if (val->map[i][j] == val->cset.empty)
				val->tab[i][j] = 1;
			else
				val->tab[i][j] = 0;
			j++;
		}
		val->tab[i][j] = -1;
		i++;
	}
	val->tab[i] = 0;
	return (1);
}
