/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:50:24 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 22:55:13 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_fill_board(char **board, int dim)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < dim)
	{
		while (j < dim)
			board[i][j++] = '0';
		i++;
		j = 0;
	}
	return (board);
}

char	**board_init(int dim)
{
	char	**board;
	int		i;

	i = 0;
	board = malloc(sizeof(char *) * (dim + 1));
	board[dim] = NULL;
	while (i < dim)
	{
		board[i] = malloc(sizeof(char) * (dim + 1));
		board[i][dim] = '\0';
		i++;
	}
	return (ft_fill_board(board, dim));
}
