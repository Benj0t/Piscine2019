/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreho <mreho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:31:33 by mreho             #+#    #+#             */
/*   Updated: 2019/08/22 22:47:07 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char	*ft_realloc(char *src, size_t size)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (size + BUF_SIZE + 1))))
		return (0);
	ft_strncpy(dest, src, size);
	free(src);
	return (dest);
}

char	*getdata(int desc)
{
	int		ret;
	int		total;
	char	*data;

	if (!(data = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (0);
	ret = read(desc, data, BUF_SIZE);
	total = ret;
	while (ret == BUF_SIZE)
	{
		if (!(data = (char *)ft_realloc(data, total)))
			return (0);
		ret = read(desc, &data[total], BUF_SIZE);
		total += ret;
	}
	if (ret < 0 || total == 0)
		return (0);
	data[total] = 0;
	return (data);
}

char	*readfile(char *file, int stdinput)
{
	int		desc;
	char	*data;

	desc = 0;
	if (stdinput == 0)
	{
		if ((desc = open(file, O_RDONLY)) < 0)
			return (0);
		if (!(data = getdata(desc)))
			return (0);
		close(desc);
	}
	else
	{
		if (!(data = getdata(desc)))
			return (0);
	}
	return (data);
}
