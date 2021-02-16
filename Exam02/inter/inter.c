/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:26:59 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 18:34:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printed(char c, char *str, int i)
{
	while (--i >= 0)
		if (str[i] == c)
			return(1);
	return(-1);
}

int		ft_match(char c, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return(1);
	}
	return(-1);
}

void	ft_inter(char *str, char *to_find)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_match(str[i],to_find) > 0)
			if (ft_printed(str[i], str, i) < 0)
				ft_putchar(str[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return(0);
}
