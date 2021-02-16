/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:24:46 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/22 22:44:39 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int		ft_error(t_point *list, t_point *l_ref, int x)
{
	ft_free(list);
	ft_free(l_ref);
	(x == 1) ? ft_putendl("Dict Error") : ft_putendl("Error");
	return (0);
}

int		ft_arg(char *dict, char *nb, t_point *l_ref)
{
	t_point *list;

	list = ft_parse(0, 0, open(dict, O_RDONLY));
	if (list)
	{
		ft_fill(open(dict, O_RDONLY), list);
		list = ft_sort_list(list, 0, NULL);
	}
	else
		return (ft_error(l_ref, list, 1));
	if (ft_check(l_ref, list) < 0 || ft_str_is_num(nb) == -1)
		return (ft_error(list, l_ref, (ft_str_is_num(nb) == -1) ? 0 : 1));
	ft_calc_million(ft_atoi(nb), list, 0);
	ft_free(list);
	ft_free(l_ref);
	return (0);
}

int		main(int ac, char **av)
{
	t_point *l_ref;

	l_ref = ft_parse(0, 0, open("./dict/numbers.dict", O_RDONLY));
	ft_fill(open("./dict/numbers.dict", O_RDONLY), l_ref);
	l_ref = ft_sort_list(l_ref, 0, NULL);
	if (ac == 2)
	{
		if (ft_str_is_num(av[1]) == 1)
			ft_calc_million(ft_atoi(av[1]), l_ref, 0);
		else
			return (ft_error(l_ref, NULL, 0));
	}
	if (ac == 3)
		return (ft_arg(av[1], av[2], l_ref));
	(ac != 2 && ac != 3) ? ft_putendl("Error") : 0;
	ft_free(l_ref);
	return (0);
}
