/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:02:14 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 17:13:10 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_valid_export(char *str)
{
	int flag;
	int i;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[0]) || (str[0] == '=' && str[1]))
			return (-1);
		if (str[0] == '?')
			return (-1);
		if (str[0] == '=')
			return (-1);
		else if (str[i] == '=')
			flag = 1;
	}
	if (!flag)
		return (FUNC_FAIL);
	return (FUNC_SUC);
}

void export_data(char *data)
{
	char **env;
	char *str;
	int pos;

	str = ft_strdup(data);
	env = ft_split(str, '=');
	pos = search_env_node(g_data.env_list, env[0]);
	if (pos == -1)
		add_env_node(g_data.env_list, str);
	else
		change_node_data(env[0], env[1]);
	free_str(env);
	free(str);
}

void export_error_check(char *str)
{
	int is_valid;

	is_valid = check_valid_export(str);
	if (is_valid == FUNC_SUC)
	{
		export_data(str);
		g_data.exit_code = 0;
	}
	else if (is_valid == FUNC_FAIL)
		g_data.exit_code = 1;
	else
		ft_custom_err2("export: `", str, "\': not a valid identifier");
}

void ft_export(t_tree *node)
{
	char **env;
	int i;

	env = ft_split(node->str, ' ');
	if (!env[1])
	{
		ft_env(node, 1);
		return ;
	}
	i = 0;
	while (env[++i])
		export_error_check(env[i]);
	free_str(env);
	free(g_data.param->envp);
	g_data.param->envp = node_to_str(g_data.env_list->head);
}
