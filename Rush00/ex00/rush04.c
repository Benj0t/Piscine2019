/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:21:59 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/03 18:23:25 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_square(char a, char b, char c, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x <= 0 || y <= 0)
		return ;
	i = x;
	j = y;
	while (j > 0)
	{
		if (j == y)
			ft_print_square('A', 'B', 'C', x);
		else if (j == 1)
			ft_print_square('C', 'B', 'A', x);
		else
			ft_print_square('B', ' ', 'B', x);
		j--;
	}
}
