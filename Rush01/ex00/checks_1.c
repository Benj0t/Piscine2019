/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:48:11 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:03:40 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_parse_board(char **board, int *x, int *y, int dim)
{
	while (board[*y] && board[*y][*x] != '0')
	{
		*x += 1;
		if (*x == dim)
		{
			*y = *y + 1;
			*x = 0;
		}
	}
}

int		ft_row_l(char **grille, char c, int dim)
{
	char	tmp;
	int		count;
	int		x2;
	int		x;
	int		y;

	x = ft_pos_x(grille, dim);
	y = ft_pos_y(grille, dim);
	x2 = 0;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (grille[y][x2])
	{
		if (grille[y][x2] > tmp)
		{
			tmp = grille[y][x2];
			count++;
		}
		x2++;
	}
	grille[y][x] = '0';
	return ((count <= (g_input[2 * dim + y] - 48)) ? 1 : -1);
}

int		ft_col_u(char **grille, char c, int dim)
{
	char	tmp;
	int		count;
	int		y2;
	int		x;
	int		y;

	x = ft_pos_x(grille, dim);
	y = ft_pos_y(grille, dim);
	y2 = 0;
	tmp = '0';
	count = 0;
	grille[y][x] = c;
	while (grille[y2])
	{
		if (grille[y2][x] > tmp)
		{
			tmp = grille[y2][x];
			count++;
		}
		y2++;
	}
	grille[y][x] = '0';
	return ((count <= (g_input[x] - 48)) ? 1 : -1);
}

int		ft_check(char **board, char c, int x, int dim)
{
	int y;

	y = ft_pos_y(board, dim);
	if (y == dim - 1)
	{
		if (ft_end_col_d(board, x, c, dim) < 0 ||
			ft_end_col_u(board, x, c, dim) < 0)
			return (-1);
	}
	if (ft_col_u(board, c, dim) < 0)
		return (-1);
	if (x == dim - 1)
	{
		if (ft_end_row_r(board, y, c, dim) < 0 ||
			ft_end_row_l(board, y, c, dim) < 0)
			return (-1);
	}
	if (ft_row_l(board, c, dim) < 0)
		return (-1);
	return (1);
}
