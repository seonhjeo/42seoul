/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:00:54 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/27 13:20:25 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_reslist(t_ps *res)
{
	t_ps	*temp;

	temp = res;
	while (temp)
	{
		ft_putendl(temp->command);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	t_ps	*res;
	int		len;

	len = check_and_save_data(argc, argv, &a);
	if (len == ERROR)
		return (ERROR);
	b = NULL;
	a_to_b(len, &a, &b, &res);
	print_reslist(res);
	free_list(&a);
	free_list(&b);
	free_list(&res);
	return (SUCCESS);
}
