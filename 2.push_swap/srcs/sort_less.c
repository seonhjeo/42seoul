/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:44:23 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:33:17 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_pa(t_ps **a, t_ps **b, t_ps **res, int len)
{
	int		i;

	i = 0;
	while (i < len)
		i += pa(a, b, res);
	return ;
}

void	sort_two_a(t_ps **temp, t_ps **res)
{
	if (*temp && (*temp)->next)
	{
		if ((*temp)->value > (*temp)->next->value)
			sa(temp, 1, res);
	}
	return ;
}

void	sort_two_b(t_ps **temp, t_ps **res)
{
	if (*temp && (*temp)->next)
	{
		if ((*temp)->value < (*temp)->next->value)
			sb(temp, 1, res);
	}
	return ;
}

void	sort_under_three_a(int len, t_ps **a, t_ps **b, t_ps **res)
{
	int	n;

	n = get_list_length(a);
	if (len <= 1)
		return ;
	if (len == 2)
		return (sort_two_a(a, res));
	else if (len == 3 && n == 3)
		sort_three_a(a, res);
	else if (len == 3 && n != 3)
		sort_three_a_onestack(a, res);
	else if (len == 4)
		sort_four_a(a, b, res);
	else if (len == 5)
		sort_five_a(a, b, res);
}

void	sort_under_three_b(int len, t_ps **a, t_ps **b, t_ps **res)
{
	int	n;

	n = get_list_length(b);
	if (len == 1)
		pa(a, b, res);
	else if (len == 2)
	{
		sort_two_b(b, res);
		do_pa(a, b, res, 2);
	}
	else if (len == 3 && is_sorted(b, len, 2))
		do_pa(a, b, res, 3);
	else if (len == 3 && !is_sorted(b, len, 2) && n == 3)
		sort_three_b(a, b, res);
	else if (len == 3 && !is_sorted(b, len, 2) && n != 3)
		sort_three_b_onestack(a, b, res);
	else if (len == 4)
		sort_four_b(a, b, res);
	else if (len == 5)
		sort_five_b(a, b, res);
	return ;
}
