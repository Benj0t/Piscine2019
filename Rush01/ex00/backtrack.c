/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:42:17 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:01:26 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_ch_lc(char **grille, int x, int y, char c)
{
	int y2;

	y2 = 0;
	while (y2 < count_args(g_input) / 4)
	{
		if (grille[y2][x] == c)
			return (-1);
		y2++;
	}
	x = 0;
	while (grille[y][x])
	{
		if (grille[y][x] == c)
			return (-1);
		x++;
	}
	return (1);
}

int		ft_backtrack(char **board, int y, int x, int dim)
{
	char c;

	c = '0';
	while (++c <= dim + 48)
	{
		ft_parse_board(board, &x, &y, dim);
		if (y == dim)
			return (1);
		if (ft_check(board, c, x, dim) < 0 || ft_ch_lc(board, x, y, c) < 0)
		{
			if (c == dim + 48)
				return (-1);
		}
		else
		{
			board[y][x] = c;
			if (ft_backtrack(board, 0, 0, dim) < 0)
			{
				board[y][x] = '0';
				if (c == dim + 48)
					return (-1);
			}
		}
	}
	return (1);
}
