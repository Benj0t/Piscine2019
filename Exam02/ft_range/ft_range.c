/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:49:17 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 19:38:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int nb)
{
	return((nb < 0) ? -nb : nb);
}

int		*ft_fill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (end - start + 1))))
		return(NULL);
	while (start <= end)
		tab[i++] = start++;
	return(tab);
}

int		*ft_ufill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (start - end + 1))))
		return(NULL);
	while (start >= end)
		tab[i++] = start--;
	return(tab);
}

int		*ft_end_mfill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (start + ft_abs(end) + 1))))
		return(NULL);
	while (start >= end)
		tab[i++] = start--;
	return(tab);
}

int		*ft_start_mfill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (ft_abs(start) + end + 1))))
		return(NULL);
	while (start <= end)
		tab[i++] = start++;
	return(tab);
}

int		*ft_smines_fill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (ft_abs(end) -  ft_abs(start) + 1))))
		return(NULL);
	while (start >= end)
		tab[i++] = start--;
	return(tab);
}

int		*ft_emines_fill(int start, int end)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * (ft_abs(start) -  ft_abs(end) + 1))))
		return(NULL);
	while (start <= end)
		tab[i++] = start++;
	return(tab);
}

int		*ft_range(int start, int end)
{
	int *tab;
	if (start >= 0 && end >= 0)
	{
		if (start < end)
			return(ft_fill(start, end));
		else if (start > end)
			return(ft_ufill(start, end));
		else
		{
			if (!(tab = (int *)malloc(sizeof(int) * (1))))
				return(NULL);
			tab[0] = start;
			return(tab);
		}
	}
	else if (start >= 0 && end < 0)
		return(ft_end_mfill(start, end));
	else if (start < 0 && end >= 0)
		return(ft_start_mfill(start, end));
	else if (start < 0 && end < 0)
	{
		if (start > end)
			return(ft_smines_fill(start, end));
		else if (start < end)
			return(ft_emines_fill(start, end));
		else
		{
			if (!(tab = (int *)malloc(sizeof(int) * (1))))
				return(NULL);
			tab[0] = start;
			return(tab);

		}
	}
	return(0);
}
