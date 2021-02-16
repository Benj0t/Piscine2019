/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:08:18 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 20:10:45 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_pos_x(char **board, int dim)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (board[y][x] != '0')
	{
		if (x == dim)
		{
			y++;
			x = 0;
		}
		x++;
	}
	return (x);
}

int		ft_pos_y(char **board, int dim)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (board[y][x] != '0')
	{
		if (x == dim)
		{
			y++;
			x = 0;
		}
		x++;
	}
	return (y);
}
