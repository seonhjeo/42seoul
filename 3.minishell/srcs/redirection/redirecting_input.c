/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecting_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:22:14 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:23:14 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirecting_input(t_tree *node)
{
	int fd;
	int res;

	fd = open(node->str, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("minishell: %s: Is a directory\n", node->str);
		g_data.exit_code = 1;
		return (1);
	}
	dup2(fd, STDIN);
	close(fd);
	res = do_cmd();
	return (res);
}
