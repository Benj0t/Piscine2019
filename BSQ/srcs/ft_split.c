/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:45:34 by mreho             #+#    #+#             */
/*   Updated: 2019/08/19 13:56:29 by mreho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		countwords(char *str, char *charset)
{
	int	i;
	int	j;
	int	n;
	int	last;

	i = 0;
	n = 0;
	last = -1;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				if (last != i - 1)
					n++;
				last = i;
			}
			j++;
		}
		i++;
	}
	return (n + 1);
}

int		wordlen(char *str, char *charset, int pos)
{
	int	i;
	int	j;

	i = pos;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i - pos);
			j++;
		}
		i++;
	}
	return (i - pos);
}

int		nextword(char *str, char *charset, int pos)
{
	int	i;
	int	j;

	i = pos;
	j = 0;
	while (str[i] && charset[j])
	{
		if (str[i] == charset[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		n;
	int		wl;
	char	**tab;

	i = nextword(str, charset, 0);
	n = 0;
	if (!(tab = malloc(sizeof(char *) * (countwords(str, charset) + 1))))
		return (0);
	while (str[i])
	{
		j = 0;
		wl = wordlen(str, charset, i);
		if (!(tab[n] = malloc(sizeof(char) * (wl + 1))))
			return (0);
		while (j < wl)
			tab[n][j++] = str[i++];
		tab[n++][j] = 0;
		i = nextword(str, charset, i);
	}
	tab[n] = 0;
	return (tab);
}
