/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:41:08 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 14:13:17 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(t_ps **a)
{
	t_ps	*current;
	t_ps	*runner;

	current = (*a);
	while (current)
	{
		runner = current;
		while (runner->next)
		{
			if (runner->next->value == current->value)
			{
				ft_putstr("Error\nDuplicates, freeing list\n");
				free_list(a);
				return (ERROR);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (SUCCESS);
}

int	check_datatype(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9')
				&& str[i][j] != '-' && str[i][j] != ' ')
			{
				ft_putstr("Error\nNot valid input, freeing string\n");
				free_string(str);
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	input_element(char **temp, t_ps **a)
{
	int		value;
	int		len;

	len = 0;
	while (temp[len])
	{
		if (ft_atoi(temp[len], &value) == ERROR)
			return (ERROR);
		if (ft_lstadd_back_ps(a, value, "") == ERROR)
			return (ERROR);
		len++;
	}
	return (len);
}

int	check_and_save_data(int argc, char **str, t_ps **a)
{
	char	**temp;
	int		len;
	int		v;
	int		i;

	if (argc == 1)
		return (ERROR);
	len = 0;
	i = 1;
	while (str[i])
	{
		temp = ft_split(str[i], ' ');
		if (check_datatype(temp) == ERROR)
			return (ERROR);
		v = input_element(temp, a);
		if (v == ERROR)
			return (ERROR);
		len += v;
		i++;
		free_string(temp);
	}
	if (check_duplicate(a) == ERROR)
		return (ERROR);
	return (len);
}
