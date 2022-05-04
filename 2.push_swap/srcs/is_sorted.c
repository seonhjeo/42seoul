/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:51:51 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/25 17:04:48 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_ps **list, int len, int flag)
{
	t_ps	*temp;
	int		i;

	temp = (*list);
	i = 0;
	while (i < len)
	{
		if (temp->next != 0)
		{
			if (flag == 1)
			{
				if (temp->value > temp->next->value)
					return (0);
			}
			if (flag == 2)
			{
				if (temp->value < temp->next->value)
					return (0);
			}
		}
		temp = temp->next;
		i++;
	}
	return (1);
}
