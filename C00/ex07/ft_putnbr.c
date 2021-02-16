/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:55:57 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/01 09:33:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	(nb < 0) ? ft_putchar('-') : 0;
	n = (nb < 0) ? -nb : nb;
	(n >= 10) ? ft_putnbr((int)(n / 10)) : 0;
	ft_putchar(n % 10 + '0');
}
