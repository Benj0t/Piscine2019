/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:03:56 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/17 10:44:49 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_intlen(int nb, char *base)
{
	int count;

	count = 0;
	while (nb)
	{
		nb /= ft_strlen(base);
		count++;
	}
	return ((count == 0) ? 1 : count);
}

char	*ft_itoa_base(int nb, char *base)
{
	char			*str;
	unsigned int	tmp;
	int				count;
	unsigned int	n;

	count = (nb < 0) ? 1 : 0;
	tmp = (nb < 0) ? -nb : nb;
	n = (nb < 0) ? -nb : nb;
	count = ft_intlen(tmp, base);
	count += (nb < 0) ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count--] = '\0';
	while (count != -1)
	{
		str[count--] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	(nb < 0) ? str[0] = '-' : 0;
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;
	char	*str;

	if (ft_check(base_to) < 0 || ft_check(base_from) < 0)
		return (NULL);
	tmp = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(tmp, base_to);
	return (str);
}
