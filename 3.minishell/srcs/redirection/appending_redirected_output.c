/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appending_redirected_output.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:26:19 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:36:18 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int do_cmd()
{
	if (!exe_builtin(g_data.next_cmd) && !ft_cmd(g_data.next_cmd))
	{
		ft_custom_err(g_data.next_cmd->left->str, "command not found");
		return (127);
	}
	return (0);
}

int	appending_redirected_output(t_tree *node)
{
	int	fd;
	int res;

	fd = open(node->str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_redirection_err(node->str, 21);
		g_data.exit_code = 1;
		return (1);
	}
	dup2(fd, STDOUT);
	close(fd);
	res = do_cmd();
	return (res);
}
