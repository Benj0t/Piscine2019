/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 20:33:48 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 21:44:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_word(char *str)
{
	int count = 0;
	int i = 0;
	while (str[i])
	{
		while (str[i] &&(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (str[i] && (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')))
			count++;
		while (str[i] && (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')))
			i++;
	}
	return(count);
}

int ft_len_word(char *str)
{
	static int i;
	int count = 0;
	while (str[i] &&(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i] && (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')))
	{
		count++;
		i++;
	}
	return(count);
}

void	ft_fill(char *tab, char *str)
{
	static int i;
	int j;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i] && (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')))
	{
		tab[j] = str[i];
		j++;
		i++;
	}
}	
char **ft_split(char *str)
{
	char **tab;
	int i;
	int tmp;
	int count;
	count = ft_count_word(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return(NULL);
	tab[count] = NULL;
	i = 0;
	while (i < count)
	{
		tmp = ft_len_word(str);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (tmp + 1))))
			return(NULL);
		tab[i][tmp] = '\0';
		i++;
	}
	i = 0;
	while (i <= count)
	{
		ft_fill(tab[i], str);
		i++;
	}
	return(tab);
}
