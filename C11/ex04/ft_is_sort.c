/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:17:40 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/21 09:32:21 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 1;
	while (i < length && tab[0] < tab[1])
	{
		if ((*f)(tab[i], tab[i - 1]) < 0)
			return (0);
		i++;
	}
	while (i < length && tab[0] > tab[1])
	{
		if ((*f)(tab[i], tab[i - 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
