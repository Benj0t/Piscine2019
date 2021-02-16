/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:05:14 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/13 09:40:15 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		ft_is_place(int pos, int *tab)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		if (tab[i] == tab[pos] || ft_abs(tab[i] - tab[pos]) == ft_abs(i - pos))
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_sol(int n, int *tab)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			if (tab[i] == j)
			{
				nb = tab[i] - 1;
				ft_putchar(nb + 48);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int		ft_ten_queens_puzzle(void)
{
	int	k;
	int	count;
	int	tab[11];

	k = 1;
	tab[k] = 0;
	count = 0;
	while (k)
	{
		while (++tab[k] <= 10 && ft_is_place(k, tab) == 0)
			;
		if (tab[k] <= 10)
		{
			if (k == 10)
			{
				ft_print_sol(10, tab);
				count++;
			}
			else
				tab[++k] = 0;
		}
		else
			k--;
	}
	return (count);
}
