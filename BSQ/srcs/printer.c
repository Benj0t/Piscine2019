/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:32:39 by mreho             #+#    #+#             */
/*   Updated: 2019/08/21 22:18:49 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

void	printgrids(t_stock *val)
{
	unsigned int	i;

	i = 0;
	while (i < val->tbl.height)
	{
		write(1, val->map[i++], val->tbl.weight);
		write(1, "\n", 1);
	}
}
