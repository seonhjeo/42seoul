/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:38:01 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/25 14:24:18 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_ps **a, t_ps **b, t_ps **res)
{
	sa(a, 0, res);
	sb(b, 0, res);
	ft_lstadd_back_ps(res, 0, "ss");
	return (1);
}

int	rr(t_ps **a, t_ps **b, t_ps **res)
{
	ra(a, 0, res);
	rb(b, 0, res);
	ft_lstadd_back_ps(res, 0, "rr");
	return (1);
}

int	rrr(t_ps **a, t_ps **b, t_ps **res)
{
	rra(a, 0, res);
	rrb(b, 0, res);
	ft_lstadd_back_ps(res, 0, "rrr");
	return (1);
}
