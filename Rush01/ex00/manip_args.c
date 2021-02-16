/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:20:07 by rquincho          #+#    #+#             */
/*   Updated: 2019/08/11 23:08:14 by rquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		args_count(char *raw_args)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (raw_args[i])
	{
		if (raw_args[i] >= '1' && raw_args[i] <= '9' &&
			(raw_args[i + 1] == ' ' || raw_args[i + 1] == '\0'))
		{
			i++;
			n++;
		}
		else
		{
			if (raw_args[i] == ' ' && raw_args[i + 1] >= '1' &&
				raw_args[i + 1] <= '9' && i > 0)
			{
				i++;
			}
		}
	}
	return (n);
}

int		args_check_1(char *raw_args)
{
	int i;

	i = 0;
	while (raw_args[i])
	{
		if (raw_args[i] >= '1' && raw_args[i] <= '9' &&
			(raw_args[i + 1] == ' ' || raw_args[i + 1] == '\0'))
		{
			i++;
		}
		else
		{
			if (raw_args[i] == ' ' && raw_args[i + 1] >= '1' &&
				raw_args[i + 1] <= '9' && i > 0)
				i++;
			else
				return (-1);
		}
	}
	return (1);
}

int		args_check_2(char *raw_args)
{
	int i;
	int dim;

	i = 0;
	dim = args_count(raw_args) / 4;
	while (raw_args[i])
	{
		if (raw_args[i] == ' ')
		{
			i++;
		}
		if (raw_args[i] < '1' || raw_args[i] > dim + 48)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int		args_are_valid(char *raw_args)
{
	if (args_check_1(raw_args) < 0)
	{
		return_error();
		return (-1);
	}
	if (args_count(raw_args) % 4 != 0 || args_count(raw_args) / 4 < 3
		|| args_count(raw_args) / 4 > 9)
	{
		return_error();
		return (-1);
	}
	if (args_check_2(raw_args) < 0)
	{
		return_error();
		return (-1);
	}
	return (1);
}

char	*args_interpret(char *raw_args)
{
	char	*args;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	args = malloc(sizeof(char *) * args_count(raw_args) + 1);
	while (raw_args[i])
	{
		if (raw_args[i] != ' ')
		{
			args[nb] = raw_args[i];
			nb++;
		}
		i++;
	}
	args[nb] = '\0';
	return (args);
}
