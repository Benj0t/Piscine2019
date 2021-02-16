/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_n_rows_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:01:35 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:00:45 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_check_col_d(char **grille, int x, int dim)
{
	char	tmp;
	int		count;
	int		y;

	y = dim - 1;
	tmp = '0';
	count = 0;
	while (y >= 0)
	{
		if (grille[y][x] > tmp)
		{
			tmp = grille[y][x];
			count++;
		}
		y--;
	}
	return ((count == (g_input[x + dim] - 48)) ? 1 : -1);
}

int		ft_check_col_u(char **grille, int x, int dim)
{
	char	tmp;
	int		count;
	int		y;

	y = 0;
	tmp = '0';
	count = 0;
	while (y <= dim - 1)
	{
		if (grille[y][x] > tmp)
		{
			tmp = grille[y][x];
			count++;
		}
		y++;
	}
	return ((count == (g_input[x] - 48)) ? 1 : -1);
}

int		ft_check_row_r(char **grille, int y, int dim)
{
	char	tmp;
	int		count;
	int		x;

	x = dim - 1;
	tmp = '0';
	count = 0;
	while (x >= 0)
	{
		if (grille[y][x] > tmp)
		{
			tmp = grille[y][x];
			count++;
		}
		x--;
	}
	return ((count == (g_input[3 * dim + y] - 48)) ? 1 : -1);
}

int		ft_check_row_l(char **grille, int y, int dim)
{
	char	tmp;
	int		count;
	int		x;

	x = 0;
	tmp = '0';
	count = 0;
	while (x <= dim - 1)
	{
		if (grille[y][x] > tmp)
		{
			tmp = grille[y][x];
			count++;
		}
		x++;
	}
	return ((count == (g_input[2 * dim + y] - 48)) ? 1 : -1);
}
