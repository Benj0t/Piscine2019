/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:10:48 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/13 18:23:37 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	unsigned int try;
	unsigned int n;

	n = (unsigned int)nb;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	try = 0;
	if (nb > 1000000000)
		try = 31500;
	if (nb > 2140000000)
		try = 46200;
	if (nb > 2000000000)
		try = 44000;
	if (nb > 100000000)
		try = 10000;
	if (nb > 10000000)
		try = 3100;
	while (try * try < n)
		try++;
	if (try * try > n)
		return (0);
	return ((int)try);
}
