/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:41:01 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:55:04 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_data(t_data *data)
{
	data->i = 0;
	data->pivotb = 0;
	data->pivots = 0;
	data->pnum = 0;
	data->ranum = 0;
	data->rbnum = 0;
}

int	get_list_length(t_ps **lst)
{
	t_ps	*temp;
	int		i;

	temp = (*lst);
	if (!temp)
		return (0);
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
