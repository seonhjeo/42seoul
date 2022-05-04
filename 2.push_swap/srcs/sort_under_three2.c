/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_three2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:00:11 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:54:23 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_a_onestack2(t_ps **temp, t_ps **res, t_numcheck *num)
{
	if (num->n1 > num->n3 && num->n3 > num->n2)
	{
		sa(temp, 1, res);
		ra(temp, 1, res);
		sa(temp, 1, res);
		rra(temp, 1, res);
	}
	if (num->n2 > num->n3 && num->n3 > num->n1)
	{
		ra(temp, 1, res);
		sa(temp, 1, res);
		rra(temp, 1, res);
	}
	if (num->n2 > num->n1 && num->n1 > num->n3)
	{
		ra(temp, 1, res);
		sa(temp, 1, res);
		rra(temp, 1, res);
		sa(temp, 1, res);
	}
	return ;
}

void	sort_three_a_onestack(t_ps **temp, t_ps **res)
{
	t_numcheck	num;

	num.n1 = (*temp)->value;
	num.n2 = (*temp)->next->value;
	num.n3 = (*temp)->next->next->value;
	if (num.n3 > num.n1 && num.n1 > num.n2)
		sa(temp, 1, res);
	if (num.n1 > num.n2 && num.n2 > num.n3)
	{
		sa(temp, 1, res);
		ra(temp, 1, res);
		sa(temp, 1, res);
		rra(temp, 1, res);
		sa(temp, 1, res);
	}
	return (sort_three_a_onestack2(temp, res, &num));
}

void	sort_three_b_onestack2(t_ps **a, t_ps **b, t_ps **res, t_numcheck *num)
{
	if (num->n1 < num->n3 && num->n3 < num->n2)
	{
		sb(b, 1, res);
		pa(a, b, res);
		sb(b, 1, res);
		pa(a, b, res);
		pa(a, b, res);
	}
	if (num->n2 < num->n3 && num->n3 < num->n1)
	{
		pa(a, b, res);
		sb(b, 1, res);
		pa(a, b, res);
		pa(a, b, res);
	}
	if (num->n2 < num->n1 && num->n1 < num->n3)
	{
		pa(a, b, res);
		sb(b, 1, res);
		pa(a, b, res);
		sa(a, 1, res);
		pa(a, b, res);
	}
	return ;
}

void	sort_three_b_onestack(t_ps **a, t_ps **b, t_ps **res)
{
	t_numcheck	num;

	num.n1 = (*b)->value;
	num.n2 = (*b)->next->value;
	num.n3 = (*b)->next->next->value;
	if (num.n3 < num.n1 && num.n1 < num.n2)
	{
		sb(b, 1, res);
		pa(a, b, res);
		pa(a, b, res);
		pa(a, b, res);
	}
	if (num.n1 < num.n2 && num.n2 < num.n3)
	{
		rb(b, 1, res);
		sb(b, 1, res);
		pa(a, b, res);
		pa(a, b, res);
		rrb(b, 1, res);
		pa(a, b, res);
	}
	return (sort_three_b_onestack2(a, b, res, &num));
}
