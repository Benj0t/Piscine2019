/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:12:16 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/15 10:50:27 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	tab = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(tab = (int*)malloc(sizeof(int) * (max - min + 1))))
		return (-1);
	tab[max - min] = 0;
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}
