/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:35:03 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 17:26:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_valid_unset(char *str)
{
	int i;

	i = -1;
	if (str[0] == '?')
		return (FUNC_FAIL);
	while (str[++i])
		if (ft_isdigit(str[0]) || str[i] == '=')
			return (FUNC_FAIL);
	return (FUNC_SUC);
}

void ft_unset(t_tree *node)
{
	char **env;
	int i;

	g_data.exit_code = 0;
	env = ft_split(node->str, ' ');
	i = 0;
	while (env[++i])
	{
		if (check_valid_unset(env[i]))
			delete_env_node(g_data.env_list, env[i]);
		else
			ft_custom_err2("unset: `", env[i], "\': not a valid identifier");
	}
	free_str(env);
	free(g_data.param->envp);
	g_data.param->envp = node_to_str(g_data.env_list->head);
}
