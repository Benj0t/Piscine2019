/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:40:50 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/18 16:57:11 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int			ft_wlen(int *fd, char *buffer)
{
	int count;
	int f;

	f = *fd;
	count = 0;
	while (buffer[0] > 32 && buffer[0] < 127)
	{
		count++;
		read(*fd, buffer, 1);
	}
	*fd = f;
	return ((buffer[0] == '\n' || buffer[0] == '\0') ? count : -1);
}

void		ft_addlist_end(t_point **list, t_point *tmp)
{
	t_point *i;

	i = *list;
	if (i)
	{
		while (i->next)
			i = i->next;
		tmp->next = NULL;
		i->next = tmp;
	}
	else
		*list = tmp;
}

void		*ft_free(t_point *tab)
{
	t_point *tmp;

	while (tab)
	{
		tmp = tab->next;
		free(tab);
		tab = tmp;
	}
	return (NULL);
}

int			ft_parse2(char *buffer, int *fd, t_point **list, int nb)
{
	t_point	*tmp;
	int		wlen;

	while (buffer[0] == ' ')
		read(*fd, buffer, 1);
	if (buffer[0] != ':')
		return (0);
	read(*fd, buffer, 1);
	while (buffer[0] == ' ')
		read(*fd, buffer, 1);
	if ((buffer[0] > 32 && buffer[0] < 127) && (wlen = ft_wlen(fd, buffer)) > 0)
	{
		if (!(tmp = (t_point *)malloc(sizeof(t_point))))
			return (0);
		if ((tmp->trad = malloc(sizeof(t_point) * (wlen + 1))))
		{
			tmp->nb = nb;
			tmp->next = NULL;
			ft_addlist_end(list, tmp);
			return (1);
		}
	}
	return (0);
}

t_point		*ft_parse(int nb, int bool, int fd)
{
	t_point	*list;
	char	buffer[1];

	list = NULL;
	if (fd == -1)
		return (NULL);
	buffer[0] = 'a';
	while (read(fd, buffer, 1))
	{
		while (buffer[0] == '\n')
			if (!read(fd, buffer, 1))
				return (list);
		bool = 0;
		nb = 0;
		while (buffer[0] >= '0' && buffer[0] <= '9')
		{
			bool = 1;
			nb = nb * 10 + (buffer[0] - 48);
			read(fd, buffer, 1);
		}
		if (bool == 0 || ft_parse2(buffer, &fd, &list, nb) == 0)
			return (ft_free(list));
	}
	close(fd);
	return (list);
}
