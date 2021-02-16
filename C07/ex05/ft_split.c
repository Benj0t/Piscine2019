/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:32 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/14 18:35:13 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_find_ch(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
		{
			return (-1);
		}
	}
	return (1);
}

int		ft_count_word(char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (ft_find_ch(str[i], charset) < 0))
			i++;
		if (str[i] && (ft_find_ch(str[i], charset) > 0))
			count++;
		while (str[i] && (ft_find_ch(str[i], charset) > 0))
			i++;
	}
	return (count);
}

int		ft_len_word(char *str, char *charset)
{
	static int	i;
	int			count;

	count = 0;
	while (str[i] && (ft_find_ch(str[i], charset) < 0))
		i++;
	while (str[i] && (ft_find_ch(str[i], charset) > 0))
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_fill(char *tab, char *str, char *charset)
{
	static int	i;
	int			j;

	j = 0;
	while (str[i] && ft_find_ch(str[i], charset) < 0)
		i++;
	while (str[i] && ft_find_ch(str[i], charset) > 0)
	{
		tab[j] = str[i];
		j++;
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		tmp;
	int		count;

	count = ft_count_word(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	i = 0;
	while (i < count)
	{
		tmp = ft_len_word(str, charset);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (tmp + 1))))
			return (NULL);
		tab[i][tmp] = '\0';
		i++;
	}
	i = 0;
	while (i <= count)
	{
		ft_fill(tab[i], str, charset);
		i++;
	}
	return (tab);
}
