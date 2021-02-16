/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:46:14 by abarbour          #+#    #+#             */
/*   Updated: 2019/08/18 17:22:16 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int		ft_pos(int nb, t_point *check)
{
	while (check)
	{
		if (check->nb == nb)
			return (1);
		check = check->next;
	}
	return (-1);
}

int		ft_check(t_point *l_ref, t_point *to_check)
{
	while (l_ref)
	{
		if (ft_pos(l_ref->nb, to_check) == -1)
			return (-1);
		l_ref = l_ref->next;
	}
	return (1);
}
