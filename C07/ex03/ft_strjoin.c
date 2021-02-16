/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:18:37 by bemoreau          #+#    #+#             */
/*   Updated: 2019/08/18 12:22:47 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_destlen(int size, char **strs, char *sep)
{
	int destlen;
	int j;
	int i;
	int seplen;

	if (size == 0)
		return (0);
	destlen = 0;
	j = 0;
	seplen = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			destlen++;
			i++;
		}
		j++;
	}
	while (sep[seplen])
		seplen++;
	destlen = destlen + ((size - 1) * seplen);
	return (destlen);
}

void	ft_onestr(char ***strs, int *j, int *currlen, char **dest)
{
	int i;

	i = 0;
	while (strs[0][*j][i])
	{
		dest[0][*currlen] = strs[0][*j][i];
		i++;
		(*currlen)++;
	}
}

void	ft_onesep(char **dest, int *currlen, char **sep)
{
	int i;

	i = 0;
	while (sep[0][i])
	{
		dest[0][*currlen] = sep[0][i];
		(*currlen)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		currlen;
	int		destlen;
	char	*dest;

	j = 0;
	currlen = 0;
	dest = "";
	destlen = ft_destlen(size, strs, sep);
	dest = malloc(4 * destlen);
	if (destlen == 0)
		return (dest);
	while (currlen < destlen)
	{
		ft_onestr(&strs, &j, &currlen, &dest);
		ft_onesep(&dest, &currlen, &sep);
		j++;
	}
	dest[destlen] = '\0';
	return (dest);
}
