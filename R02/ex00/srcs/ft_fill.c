/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:36:22 by abarbour          #+#    #+#             */
/*   Updated: 2019/08/18 23:13:18 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void		ft_fill(int fd, t_point *list)
{
	char	buffer[1];
	int		i;

	if (fd == -1)
		return ;
	buffer[0] = 'a';
	while (read(fd, buffer, 1))
	{
		while ((buffer[0] == '\n') || (buffer[0] >= '0' && buffer[0] <= '9')
				|| (buffer[0] == ' ') || (buffer[0] == ':'))
			if (!read(fd, buffer, 1))
				return ;
		i = 0;
		while (buffer[0] > 32 && buffer[0] < 127)
		{
			list->trad[i] = buffer[0];
			read(fd, buffer, 1);
			i++;
		}
		list->trad[i] = '\0';
		list = list->next;
	}
	close(fd);
}
