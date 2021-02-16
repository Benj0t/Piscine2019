/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:36:28 by mreho             #+#    #+#             */
/*   Updated: 2019/08/21 23:37:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUF_SIZE 8192

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_charset
{
	char			empty;
	char			stop;
	char			fill;
}					t_charset;

typedef struct		s_coordinates
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	max;
}					t_coordinates;

typedef struct		s_map
{
	unsigned int	height;
	unsigned int	weight;
}					t_map;

typedef struct		s_stock
{
	int				**tab;
	char			**map;
	t_map			tbl;
	t_charset		cset;
	t_coordinates	co;
}					t_stock;

char				bsq(t_stock *val);
char				*readfile(char *file, int stdinput);
t_stock				*parsedata(char *data);
void				printgrids(t_stock *val);
void				fillgrid(t_stock *val);
char				convertmap(t_stock *val);
void				findbsq(t_stock *val);

void				ft_putchar(char c, int fd);
void				ft_putstr(char *str, int fd);
char				*ft_strncpy(char *dest, char *src, unsigned int size);
char				*ft_strdup(char *src);
char				**ft_split(char *str, char *charset);
unsigned int		ft_strlen(char *str);
unsigned int		ft_strtoui(char *str);

#endif
