/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:54:56 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/04 13:12:20 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int check;

	i = 0;
	check = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9'))
		{
			if (check && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (check == 0 && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			check = 0;
		}
		else
			check = 1;
		i++;
	}
	return (str);
}
