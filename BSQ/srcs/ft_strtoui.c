/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:57:50 by mreho             #+#    #+#             */
/*   Updated: 2019/08/19 18:07:03 by mreho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strtoui(char *str)
{
	int				i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}
