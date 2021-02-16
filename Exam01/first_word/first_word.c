/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:09:01 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 18:18:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_word(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	while (str[i] && (!(str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))))
		write(1, &str[i++], 1);
	write(1, "\n", 1);

}

int		main(int argc, char **argv)
{
	(argc == 2) ? ft_first_word(argv[1]) : write(1, "\n", 1);
	return(0);
}
