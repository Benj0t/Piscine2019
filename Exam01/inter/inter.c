/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:21:50 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 18:43:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check(unsigned char c, unsigned char *str, int i)
{
	while (--i >= 0)
	{
		if (str[i] == c)
			return(-1);
	}
	return(0);

}

void	ft_inter(char *str1, char *str2)
{
	int i;
	int j;
	unsigned char *s1 = (unsigned char *)str1;
	unsigned char *s2 = (unsigned char *)str2;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (ft_check(s1[i], s1, i) == 0)
					write(1, &s1[i], 1);
				break;
			}
			j++;
		}
		i++;
		j = 0;
	}
	write(1, "\n", 1);
}



int main(int argc, char **argv)
{
	(argc == 3) ? ft_inter(argv[1], argv[2]) : write(1, "\n", 1);
}
