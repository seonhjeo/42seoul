/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:09:36 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/04 10:34:05 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	only_has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (FUNC_FAIL);
		i++;
	}
	return (FUNC_SUC);
}

int	space_or_end(char *str, int i)
{
	if (str[i] == ' ' || str[i + 1] == '\0')
		return (FUNC_SUC);
	return (FUNC_FAIL);
}

int	is_quot(char c)
{
	if (c == 34 || c == 39)
		return (FUNC_SUC);
	return (FUNC_FAIL);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (FUNC_SUC);
	return (FUNC_FAIL);
}

int	is_redir(char c)
{
	if (c == '<' || c == '>')
		return (FUNC_SUC);
	return (FUNC_FAIL);
}
