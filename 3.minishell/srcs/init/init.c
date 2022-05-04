/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:37:32 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/07 15:54:03 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**node_to_str(t_env_node *target)
{
	char		**temp;
	t_env_node	*node;
	int		len;

	len = 0;
	node = target;
	while (node)
	{
		node = node->next;
		len++;
	}
	temp = (char **)malloc(sizeof(char *) * (len + 2));
	node = target;
	len = 0;
	while (node)
	{
		temp[len] = ft_strdup(node->data);
		node = node->next;
		len++;
	}
	temp[len] = "\0";
	return (temp);
}

int init_param(char **argv)
{
    t_param *param;

    param = (t_param *)malloc(sizeof(t_param));
    if (!param)
        return (FUNC_FAIL);
    param->argv = argv;
    param->envp = node_to_str(g_data.env_list->head);
    g_data.param = param;    
    g_data.next_cmd = NULL;   
    return (FUNC_SUC);
}

int get_env_path(char **envp)
{
    char    *path;
    char    **temp;

    path = NULL;
    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
        {
            path = *envp;
            break ;
        }
        (*envp)++;
    }
    if (!path)
        return (FUNC_FAIL);
    temp = ft_split(path, '=');
    path = ft_strdup(temp[1]);
    free_str(temp);
    g_data.env_path = ft_split(path, ':');
    free(path);
    return (FUNC_SUC);
}

int init_data(char **envp)
{
    g_data.exit_code = 0;
    g_data.delete_home = 0;
    g_data.head = NULL;
	get_all_env(envp);
    if (!get_env_path(envp))
        return(ft_strerror_exit("Error: PATH initializing error"));
	
    return (FUNC_SUC);
}
