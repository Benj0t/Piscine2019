/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:42:45 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 21:51:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *front;
	t_list *back;
	
	front = *begin_list;
	back = *begin_list;
	while (front)
	{
		if (cmp(front->data, data_ref) == 0)
		{		
			tmp = front;
			front = front->next;
			back->next = front;
			free(tmp);
		}
		else
		{
			back = back->next;
			front = front->next;
		}
	}
	if (!front)
		back->next = NULL;
}
