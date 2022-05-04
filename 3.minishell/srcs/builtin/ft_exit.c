/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:47:47 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 16:41:08 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_numeric_arg(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void ft_exit(t_tree *node)
{
	char **ret;

	ret = ft_split(node->str, ' ');
	if (!ret[1])
	{
		ft_putstr_fd("exit\n", STDOUT);
		g_data.exit_code = 0;
	}
	else if (ret[2] != NULL)
	{
		ft_custom_err("exit", "too many arguments");
		return;
	}
	else if (is_numeric_arg(ret[1]))
		g_data.exit_code = ft_atoi(ret[1]);
	else
	{
		ft_custom_err("exit", "numeric argument required");
		g_data.exit_code = 255;
	}
	exit(g_data.exit_code);
	free_str(ret);
}