/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:03:38 by abarbour          #+#    #+#             */
/*   Updated: 2019/08/18 23:04:23 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int			ft_str_is_num(char *str)
{
	int i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		i++;
		if (!str[i])
			return (1);
	}
	return (-1);
}

int			ft_atoi(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] <= '9' && str[i] >= '0')
		nb = nb * 10 + (str[i++] - 48);
	return (nb);
}

void		ft_swap(t_point *t1, t_point *t2)
{
	char	*tmp;
	int		a;

	tmp = t1->trad;
	t1->trad = t2->trad;
	t2->trad = tmp;
	a = t1->nb;
	t1->nb = t2->nb;
	t2->nb = a;
}
