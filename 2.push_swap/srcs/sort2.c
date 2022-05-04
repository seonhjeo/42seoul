/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:26:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:55:23 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rr(t_data *data, t_ps **a, t_ps **b, t_ps **res)
{
	int		i;

	i = 0;
	if (data->ranum > data->rbnum)
	{
		while (i < data->rbnum)
			i += rrr(a, b, res);
		while (i < data->ranum)
			i += rra(a, 1, res);
	}
	else
	{
		while (i < data->ranum)
			i += rrr(a, b, res);
		while (i < data->rbnum)
			i += rrb(b, 1, res);
	}
}

void	a_to_b(int len, t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(a, len, 1))
		return ;
	if (len <= 5)
		return (sort_under_three_a(len, a, b, res));
	init_data(&data);
	ft_pivot(*a, &data, len);
	while (data.i < len)
	{
		if ((*a)->value >= data.pivotb)
			data.ranum += ra(a, 1, res);
		else
		{
			data.pnum += pb(a, b, res);
			if ((*b)->value >= data.pivots)
				data.rbnum += rb(b, 1, res);
		}
		data.i++;
	}
	do_rr(&data, a, b, res);
	a_to_b(data.ranum, a, b, res);
	b_to_a(data.rbnum, a, b, res);
	b_to_a(data.pnum - data.rbnum, a, b, res);
}

void	b_to_a(int len, t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(b, len, 2))
		return (do_pa(a, b, res, len));
	if (len <= 3)
		return (sort_under_three_b(len, a, b, res));
	init_data(&data);
	ft_pivot(*b, &data, len);
	while (data.i < len)
	{
		if ((*b)->value < data.pivots)
			data.rbnum += rb(b, 1, res);
		else
		{
			data.pnum += pa(a, b, res);
			if ((*a)->value < data.pivotb)
				data.ranum += ra(a, 1, res);
		}
		data.i++;
	}
	a_to_b(data.pnum - data.ranum, a, b, res);
	do_rr(&data, a, b, res);
	a_to_b(data.ranum, a, b, res);
	b_to_a(data.rbnum, a, b, res);
}
