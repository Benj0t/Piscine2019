/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:46:09 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 20:31:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *tab;
	int i;
	unsigned int s;
	unsigned int e;
	s = (start < 0) ? -start : start;
	e = (end < 0 ) ? -end : end;
	
	if ((start - end == 0) && (end - start == 0))
	{
		if (!(tab = (int *)malloc(sizeof(int) * (2))))
			return(NULL);
		tab[1] = '\0';
		tab[0] = 0;
		return(tab);
	}
	i = 0;
	if (e >= s)
		if (!(tab = (int *)malloc(sizeof(int) * ((e - s) + 1))))
			return(NULL);
	if (e < s)
		if (!(tab = (int *)malloc(sizeof(int) * ((s - e) + 1))))
			return(NULL);
	if (start <= end)
	{
		while (start <= end)
		{
			tab[i] = start;
			i++;
			start++;
		}
	}
	else if (start >= end)
	{
		while (start >= end)
		{
			tab[i] = start;
			i++;
			start--;
		}
	}	
	return(tab);
}
