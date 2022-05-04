/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecting_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:21:58 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:23:21 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_next_cmd(t_tree *node)
{
	if (node->done)
		return ;
	if (node->cmd_type == L_SIMPLE_CMD && node->done != 1)
	{
		g_data.next_cmd = node;
		node->done = 1;
		return ;
	}
	if (node->cmd_type == L_IO_REDIR && node->done != 1)
	{
		g_data.next_cmd = node;
		node->done = 1;
		return ;
	}
	if (node->left)
		find_next_cmd(node->left);
	if (node->right)
		find_next_cmd(node->right);
}

int	redirecting_output(t_tree *node)
{
	int	fd;
	int res;

	fd = open(node->str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		printf("minishell: %s: Is a directory\n", node->str);
		g_data.exit_code = 1;
		return (1);
	}
	dup2(fd, STDOUT);
	close(fd);
	res = do_cmd();
	return (res);
}
