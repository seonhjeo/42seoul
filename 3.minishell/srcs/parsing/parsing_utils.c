/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:36:14 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/04 10:34:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_word(char *str, int i)
{
	if (i < 0)
		return (FUNC_SUC);
	if (!is_pipe(str[i]) && !is_redir(str[i]))
		return (FUNC_SUC);
	return (FUNC_FAIL);
}

void	init_quote(t_quote *quote)
{
	quote->quot = '\0';
	quote->is_quoting = 0;
	quote->is_redir = 0;
	quote->is_pipe = 0;
	quote->checked = 0;
	quote->redir = '\0';
	quote->i = 0;
	quote->j = 0;
}

void	set_quote(t_quote *quote, char c, int flag)
{
	quote->quot = '\0';
	quote->is_quoting = 0;
	quote->is_redir = 0;
	quote->is_pipe = 0;
	quote->checked = 0;
	quote->redir = '\0';
	if (flag)
		quote->checked = 1;
	if (flag > 1)
		quote->j = 0;
	if (flag == 1)
	{
		quote->is_quoting = 1;
		quote->quot = c;
	}
	if (flag == 2)
	{
		quote->is_redir = 1;
		quote->redir = c;
	}
	if (flag == 3)
		quote->is_pipe = 1;
}
