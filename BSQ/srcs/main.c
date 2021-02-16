/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:50:19 by mreho             #+#    #+#             */
/*   Updated: 2019/08/22 22:46:29 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char		error(char type)
{
	if (type == 0)
		ft_putstr("Error\n", 2);
	else if (type == 1)
		ft_putstr("Map Error\n", 2);
	return (1);
}

t_stock		*handleinput(char *file, char stdinput)
{
	char	*data;
	t_stock	*val;

	if (!(data = readfile(file, stdinput)))
	{
		error(0);
		return (0);
	}
	if (!(val = parsedata(data)))
	{
		error(1);
		return (0);
	}
	free(data);
	return (val);
}

int			main(int ac, char **av)
{
	int		n;
	t_stock	*val;

	n = 1;
	if (ac == 1)
	{
		if (!(val = handleinput(av[0], 1)))
			return (1);
		if (!bsq(val))
			return (error(0));
	}
	while (n < ac)
	{
		if (!(val = handleinput(av[n++], 0)))
			return (1);
		if (!bsq(val))
			return (error(0));
	}
	printgrids(val);
	free(&val->map[-1]);
	free(val);
	return (0);
}
