/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:07:30 by mreho             #+#    #+#             */
/*   Updated: 2019/08/21 09:31:29 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (tab[i1])
	{
		i2 = 0;
		while (tab[i2])
		{
			if (ft_strcmp(tab[i1], tab[i2]) < 0)
				ft_swap(&tab[i1], &tab[i2]);
			i2++;
		}
		i1++;
	}
}
