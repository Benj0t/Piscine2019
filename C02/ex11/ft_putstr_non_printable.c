/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:02:25 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/04 07:50:33 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*base;
	unsigned char	*ustr;

	ustr = (unsigned char *)str;
	i = -1;
	base = "0123456789abcdef";
	while (ustr[++i])
	{
		if (ustr[i] >= 32 && ustr[i] < 127)
			ft_putchar(ustr[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(base[ustr[i] / 16]);
			ft_putchar(base[ustr[i] % 16]);
		}
	}
}
