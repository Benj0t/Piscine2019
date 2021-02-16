/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:45:39 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:05:18 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	return_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_show_board(char **board, int dim)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (board[y])
	{
		ft_putchar(board[y][x++]);
		ft_putchar((x == dim) ? '\n' : ' ');
		if (x == dim)
		{
			x = 0;
			y++;
		}
	}
}

int		count_args(char *args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
