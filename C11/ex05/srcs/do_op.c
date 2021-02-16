/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:18:15 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/21 09:31:47 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <do_op.h>

int		do_op(int a, char sign, int b)
{
	if (sign == '+')
		return (a + b);
	if (sign == '-')
		return (a - b);
	if (sign == '/')
		return (a / b);
	if (sign == '*')
		return (a * b);
	if (sign == '%')
		return (a % b);
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		a;
	int		b;
	char	sign;

	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		sign = *av[2];
		if ((sign == '/' || sign == '%') && b == 0)
		{
			if (sign == '/')
				ft_putstr("Stop : division by zero\n");
			else
				ft_putstr("Stop : modulo by zero\n");
			return (1);
		}
		ft_putnbr(do_op(a, sign, b));
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
