/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:59:17 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/19 15:03:46 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

void				ft_putnbr(int nb)
{
	unsigned int n;

	(nb < 0) ? ft_putchar('-') : 0;
	n = (nb < 0) ? -nb : nb;
	(n >= 10) ? ft_putnbr((int)(n / 10)) : 0;
	ft_putchar(n % 10 + '0');
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putendl(par[i].str);
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putendl(par[i++].copy);
	}
}
