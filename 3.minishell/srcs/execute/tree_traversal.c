/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_traversal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:21:29 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:37:21 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_cmd(t_tree *node)
{
	pid_t pid;
	char *path;
	char **argv;

	node->done = 1;
	path = get_path(node->left->str);
	argv = ft_split(node->right->str, ' ');
	if (!path)
	{
		g_data.exit_code = 127;
		return (FUNC_FAIL);
	}
	pid = fork();
	if (!pid)
		if (execve(path, argv, g_data.param->envp) == -1)
			return (FUNC_FAIL);
	waitpid(pid, NULL, 0);
	free_str(argv);
	free(path);
	return (FUNC_SUC);
}

void exe_redirection(t_tree *node)
{
	int res;
	pid_t pid;
	char *temp;

	node->done = 1;
	find_next_cmd(g_data.head);
	temp = ft_strtrim(node->right->str, " ");
	free(node->right->str);
	node->right->str = ft_strdup(temp);
	free(temp);
	pid = fork();
	if (!pid)
	{
		if (ft_strncmp(node->left->str, "<", ft_strlen(node->left->str)) == 0)
			g_data.exit_code = redirecting_input(node->right);
		else if (ft_strncmp(node->left->str, ">", ft_strlen(node->left->str)) == 0)
			g_data.exit_code = redirecting_output(node->right);
		else if (ft_strncmp(node->left->str, ">>", ft_strlen(node->left->str)) == 0)
			g_data.exit_code = appending_redirected_output(node->right);
		else if (ft_strncmp(node->left->str, "<<", ft_strlen(node->left->str)) == 0)
			g_data.exit_code = here_documents(node);
		exit(g_data.exit_code);
	}
	waitpid(pid, &res, 0);
	g_data.exit_code = res / 256;
	g_data.next_cmd = NULL;
}

int exe_builtin(t_tree *node)
{
	char *str;

	str = node->left->str;
	node->done = 1;
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		ft_cd(node->right);
	else if (ft_strncmp(str, "echo", ft_strlen(str)) == 0)
		ft_echo(node->right);
	else if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		ft_env(node->right, 0);
	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
		ft_exit(node->right);
	else if (ft_strncmp(str, "export", ft_strlen(str)) == 0)
		ft_export(node->right);
	else if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		ft_pwd();
	else if (ft_strncmp(str, "unset", ft_strlen(str)) == 0)
		ft_unset(node->right);
	else
		return (FUNC_FAIL);
	return (FUNC_SUC);
}

void exe_node(t_tree *node)
{
	if (node->done)
		return;
	if (node->left && node->cmd_type == L_IO_REDIR)
		exe_redirection(node);
	if (node->left && node->cmd_type == L_SIMPLE_CMD)
		if (!exe_builtin(node) && ft_cmd(node) == FUNC_FAIL)
		{
			ft_custom_err(node->left->str, "command not found");
			g_data.exit_code = 127;
		}
	if (node->cmd_type == L_PIPE && node->right)
		ft_pipe(node);
}

void tree_traversal(t_tree *node)
{
	exe_node(node);
	if (node->left)
		tree_traversal(node->left);
	if (node->right)
		tree_traversal(node->right);
}
