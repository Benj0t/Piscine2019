/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:49:37 by mreho             #+#    #+#             */
/*   Updated: 2019/08/21 21:07:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char		parsecharset(t_stock *val)
{
	char			*str;
	unsigned int	len;

	str = val->map[0];
	if ((len = ft_strlen(str)) < 4)
		return (0);
	val->cset.fill = str[len - 1];
	val->cset.stop = str[len - 2];
	val->cset.empty = str[len - 3];
	str[len - 3] = 0;
	val->tbl.height = ft_strtoui(str);
	return (1);
}

char		parsemap(t_stock *val)
{
	unsigned int	n;
	unsigned int	i;

	n = 0;
	if (!(val->tbl.weight = ft_strlen(*val->map)))
		return (0);
	while (val->map[n])
	{
		if (ft_strlen(val->map[n]) != val->tbl.weight)
			return (0);
		i = 0;
		while (val->map[n][i])
		{
			if (val->map[n][i] != val->cset.empty
			&& val->map[n][i] != val->cset.stop)
				return (0);
			i++;
		}
		n++;
	}
	if (n != val->tbl.height)
		return (0);
	return (1);
}

t_stock		*parsedata(char *data)
{
	t_stock	*val;

	if (!(val = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	if (!(val->map = ft_split(data, "\n")))
		return (0);
	if (!val->map[0] || !val->map[1])
		return (0);
	if (!parsecharset(val))
		return (0);
	val->map = &val->map[1];
	if (!parsemap(val))
		return (0);
	return (val);
}
