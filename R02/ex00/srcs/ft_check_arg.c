/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:48:11 by abarbour          #+#    #+#             */
/*   Updated: 2019/08/18 23:12:18 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

t_point		*ft_sort_list(t_point *list, int max, t_point *temp)
{
	t_point	*temp1;
	t_point *temp3;

	temp3 = (t_point *)malloc(sizeof(t_point));
	temp1 = (t_point *)malloc(sizeof(t_point));
	temp = list;
	while (temp != NULL)
	{
		max = temp->nb;
		temp1 = temp->next;
		while (temp1 != NULL)
		{
			if (max < temp1->nb)
			{
				temp3 = temp1;
				max = temp3->nb;
			}
			temp1 = temp1->next;
		}
		ft_swap(temp, temp3);
		temp = temp->next;
	}
	return (list);
}

void		ft_calc1(t_point *tmp, int nb, int bool)
{
	while (tmp && tmp->nb != nb)
		tmp = tmp->next;
	(bool == 1) ? ft_putsp(tmp->trad) : ft_putstr(tmp->trad);
}

void		ft_calc2(t_point *tmp, t_point *list, int nb, int *bool)
{
	t_point *tmp1;

	tmp1 = list;
	(*bool == 1) ? ft_putsp(tmp->trad) : ft_putstr(tmp->trad);
	*bool = 1;
	if (nb % tmp->nb != 0)
	{
		while (tmp1 && (nb % tmp->nb) != tmp1->nb)
			tmp1 = tmp1->next;
		(*bool == 1) ? ft_putsp(tmp1->trad) : ft_putstr(tmp1->trad);
	}
}

void		ft_calc_million(int nb, t_point *list, int bool)
{
	t_point *tmp;
	t_point *tmp1;

	tmp = list;
	(nb <= 20) ? ft_calc1(tmp, nb, bool) : 0;
	if (nb > 20)
	{
		tmp = list;
		while (tmp && (nb / tmp->nb == 0))
			tmp = tmp->next;
		if (nb >= 100)
		{
			tmp1 = list;
			while (tmp1 && (nb / tmp->nb) != tmp1->nb)
				tmp1 = tmp1->next;
			(nb / tmp->nb > 20) ? ft_calc_million(nb / tmp->nb, list, bool) : 0;
			if (nb / tmp->nb <= 20)
				(bool == 1) ? ft_putsp(tmp1->trad) : ft_putstr(tmp1->trad);
			ft_putsp(tmp->trad);
			nb = nb % tmp->nb;
			(nb != 0) ? ft_calc_million(nb, list, 1) : 0;
		}
		else
			ft_calc2(tmp, list, nb, &bool);
	}
}
