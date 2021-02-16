/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 08:18:09 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/07 19:47:08 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) <= 1)
		return (-1);
	i = 0;
	j = i + 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j++])
				return (-1);
		}
		i++;
		j = i + 1;
	}
	i = -1;
	while (base[++i])
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' ||
				base[i] == '\t' || base[i] == '\v' || base[i] == '\n' ||
				base[i] == '\f' || base[i] == '\r')
			return (-1);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	nb;

	nb = 0;
	if (ft_check(base) <= 0)
		return ;
	len = ft_strlen(base);
	(nbr < 0) ? ft_putchar('-') : 0;
	nb = (nbr < 0) ? -nbr : nbr;
	(nb >= len) ? ft_putnbr_base(nb / len, base) : 0;
	ft_putchar(base[nb % len]);
}
