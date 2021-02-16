/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:51:31 by bemoreau          #+#    #+#             */
/*   Updated: 2019/10/17 00:14:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnstr(unsigned char *str)
{
	int i;

	i = 0;
	while (i < 16 && str[i])
	{
		if (!((str[i] >= 0 && str[i] < 32) || str[i] == 127))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	ft_put_spaces(int check)
{
	while (check < 40)
	{
		write(1, " ", 1);
		check++;
	}
}

void	ft_put_hexa(unsigned char *str)
{
	char	*base;
	int		i;
	int		check;

	check = 0;
	i = 0;
	base = "0123456789abcdef";
	while (i < 16 && str[i])
	{
		write(1, &base[str[i] / 16], 1);
		write(1, &base[str[i] % 16], 1);
		if (i % 2 == 1)
		{
			write(1, " ", 1);
			check++;
		}
		i++;
		check += 2;
	}
	if (!str[i])
		ft_put_spaces(check);
}

void	ft_put_addr(unsigned long l)
{
	char	*base;
	int		j;
	char	tab[15];

	j = 0;
	while (j <= 14)
		tab[j++] = '0';
	j--;
	base = "0123456789abcdef";
	while (l >= 16)
	{
		tab[j--] = base[l % 16];
		l = l / 16;
	}
	j = 0;
	while (j <= 14)
		write(1, &tab[j++], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned long	l;

	i = 0;
	while (i < size)
	{
		l = (unsigned long)&addr[i];
		ft_put_addr(l);
		write(1, ":", 1);
		write(1, " ", 1);
		ft_put_hexa((unsigned char *)addr + i);
		ft_putnstr((unsigned char *)addr + i);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

int main(void)
{
	int    tab[10] = {0, 23, 150, 255,
        12, 16,  21, 42};
	ft_print_memory(tab, 8);
	return(0);
}