/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:56:29 by mreho             #+#    #+#             */
/*   Updated: 2019/08/19 13:57:08 by mreho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		srclen;
	char	*dest;

	i = 0;
	srclen = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * (srclen + 1))))
		return (0);
	while (i < srclen)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
