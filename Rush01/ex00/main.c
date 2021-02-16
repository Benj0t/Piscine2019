/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:03:50 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:17:29 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_check_args(char **grille, int dim)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (grille[y][x])
	{
		if (grille[y][x] == '0')
			return (-1);
		x++;
		if (x == dim)
		{
			x = 0;
			y++;
		}
		if (y == dim)
			return (1);
	}
	return (1);
}

int		ft_parse_board_end(char **grille, int dim)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= dim - 1)
	{
		if (ft_check_col_u(grille, x, dim) < 0 ||
			ft_check_col_d(grille, x, dim) < 0)
			return (-1);
		x++;
	}
	while (y <= dim - 1)
	{
		if (ft_check_row_r(grille, y, dim) < 0 ||
			ft_check_row_l(grille, y, dim) < 0)
			return (-1);
		y++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char **board;

	if (argc != 2)
	{
		return_error();
		return (0);
	}
	if (args_are_valid(argv[1]) < 0)
		return (0);
	g_input = args_interpret(argv[1]);
	board = board_init(args_count(argv[1]) / 4);
	ft_backtrack(board, 0, 0, args_count(argv[1]) / 4);
	if (ft_check_args(board, args_count(argv[1]) / 4) < 0
		|| ft_parse_board_end(board, args_count(argv[1]) / 4) < 0)
	{
		return_error();
		return (0);
	}
	ft_show_board(board, args_count(argv[1]) / 4);
	return (0);
}
