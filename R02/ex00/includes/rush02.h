/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:34:46 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/18 23:25:10 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_point
{
	int				nb;
	char			*trad;
	struct s_point	*next;
}					t_point;

t_point				*ft_parse(int nb, int bool, int fd);
void				ft_fill(int fd, t_point *list);
int					ft_check(t_point *l_ref, t_point *to_check);
void				*ft_free(t_point *list);
int					ft_atoi(char *str);
int					ft_str_is_num(char *str);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putsp(char *str);
void				ft_putchar(char c);
void				ft_calc_million(int nb, t_point *list, int bool);
t_point				*ft_sort_list(t_point *list, int max, t_point *temp);
void				ft_swap(t_point *t1, t_point *t2);

#endif
