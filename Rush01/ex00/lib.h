/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:46:48 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 22:58:41 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*g_input;
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	return_error(void);
void	ft_show_board(char **board, int dim);
int		count_args(char *args);
int		args_are_valid(char *raw_args);
int		args_count(char *raw_args);
char	*args_interpret(char *raw_args);
char	**board_init(int dim);
void	ft_parse_board(char **board, int *x, int *y, int dim);
int		ft_backtrack(char **board, int y, int x, int dim);
int		ft_check(char **board, char c, int x, int dim);
int		ft_pos_y(char **board, int dim);
int		ft_pos_x(char **board, int dim);
int		ft_check_col_d(char **grille, int x, int dim);
int		ft_check_col_u(char **grille, int x, int dim);
int		ft_check_row_r(char **grille, int y, int dim);
int		ft_check_row_l(char **grille, int y, int dim);
int		ft_end_col_d(char **grille, int x, char c, int dim);
int		ft_end_col_u(char **grille, int x, char c, int dim);
int		ft_end_row_r(char **grille, int y, char c, int dim);
int		ft_end_row_l(char **grille, int y, char c, int dim);

#endif
