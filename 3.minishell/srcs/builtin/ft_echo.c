/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:29:22 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/04 18:11:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int newline_option(char *str)
{
	int i;

	if (str[0] != '-')
		return (0);
	i = 0;
	while (str[++i])
		if (str[i] != 'n')
			return (0);
	return (1);
}

void ft_echo(t_tree *node)
{
	char **temp;
	int option;
	int i;

	temp = ft_split(node->str, ' ');
	if (!temp[1])
	{
		ft_putstr_fd("\n", STDOUT);
		return;
	}
	i = 0;
	option = newline_option(temp[1]);
	if (option)
		i++;
	while (temp[++i])
	{
		ft_putstr_fd(temp[i], STDOUT);
		if (temp[i + 1])
			ft_putstr_fd(" ", STDOUT);
	}
	if (!option)
		ft_putstr_fd("\n", STDOUT);
	g_data.exit_code = 0;
	free_str(temp);
}