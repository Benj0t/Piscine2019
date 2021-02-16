/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:12:05 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 22:59:36 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_end_col_d(char **grille, int x, char c, int dim)
{
	char	tmp;
	int		count;
	int		y;
	int		y2;

	y = ft_pos_y(grille, dim);
	y2 = dim - 1;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (y2 >= 0)
	{
		if (grille[y2][x] > tmp)
		{
			tmp = grille[y2][x];
			count++;
		}
		y2--;
	}
	grille[y][x] = '0';
	return ((count == (g_input[x + dim] - 48)) ? 1 : -1);
}

int		ft_end_col_u(char **grille, int x, char c, int dim)
{
	char	tmp;
	int		count;
	int		y;
	int		y2;

	y = ft_pos_y(grille, dim);
	y2 = 0;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (y2 <= dim - 1)
	{
		if (grille[y2][x] > tmp)
		{
			tmp = grille[y2][x];
			count++;
		}
		y2++;
	}
	grille[y][x] = '0';
	return ((count == (g_input[x] - 48)) ? 1 : -1);
}

int		ft_end_row_r(char **grille, int y, char c, int dim)
{
	char	tmp;
	int		count;
	int		x;
	int		x2;

	x = ft_pos_x(grille, dim);
	x2 = dim - 1;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (x2 >= 0)
	{
		if (grille[y][x2] > tmp)
		{
			tmp = grille[y][x2];
			count++;
		}
		x2--;
	}
	grille[y][x] = '0';
	return ((count == (g_input[3 * dim + y] - 48)) ? 1 : -1);
}

int		ft_end_row_l(char **grille, int y, char c, int dim)
{
	char	tmp;
	int		count;
	int		x;
	int		x2;

	x = ft_pos_x(grille, dim);
	x2 = 0;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (x2 <= dim - 1)
	{
		if (grille[y][x2] > tmp)
		{
			tmp = grille[y][x2];
			count++;
		}
		x2++;
	}
	grille[y][x] = '0';
	return ((count == (g_input[2 * dim + y] - 48)) ? 1 : -1);
}
